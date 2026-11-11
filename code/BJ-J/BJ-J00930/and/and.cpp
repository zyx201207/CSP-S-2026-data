#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2010

ll n,m,l=1,ans=0;
ll w[N],tong[N],pow2[N];
ll pl2k=0;

bool vis[N];
bool flag4=true;
bool n2k=false;
bool ai2k=true;

bool cmp(ll i,ll j)
{
    return i>j;
}

void dfs(ll x,ll r)
{
    if(x==0)
    {
        ans=max(ans,r);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(x-1,r&w[i]);
            vis[i]=false;
        }
    }
    return;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    for(int i=1;i<=31;i++)
    {
        l*=2;
        pow2[i]=l;
    }
    cin>>n>>m;
    if(pow2[(ll)log2(n)]==n) n2k=true;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        if(w[i]>=4)
        {
            flag4=false;
        }
        else
        {
            tong[w[i]]++;
        }
        if(pow2[(ll)log2(w[i])+1]!=w[i]+1) ai2k=false;
    }

    if(n<=5)
    {
        dfs(m,l-1);
        cout<<ans<< "\n";
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,w[i]);
        }
        cout<<ans<< "\n";
    }
    else if(m==n)
    {
        ans=l-1;
        for(int i=1;i<=n;i++)
        {
            ans=(ans&w[i]);
        }
        cout<<ans<< "\n";
    }
    else if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,(w[i]&w[j]));
            }
        }
        cout<<ans<< "\n";
    }
    else if(flag4)
    {
        m-=tong[3];
        if(m<=0) cout<< "3\n";
        else if(m<=tong[2]) cout<< "2\n";
        else if(m<=tong[1]) cout<< "1\n";
        else cout<< "0\n";
    }
    else if(n2k)
    {
        pl2k+=n/2;
        if(m>n/2) cout<< "0\n";
        else
        {
            for(ll i=n/4;i>=0;i/=2)
            {
                if(m>i)
                {
                    cout<<pl2k<< "\n";
                    break;
                }
                pl2k+=i;
            }
        }
    }
    else if(ai2k)
    {
        sort(w+1,w+n+1,cmp);
        cout<<w[m]<< "\n";
    }
    else cout<< "0\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t,n;
ll d,a[N],l[N],r[N],ans;
void fd(int x,int st,bool b,ll s)
{
    if(r[x]==x)
    {
        ans+=s;
        return;
    }
    if(b)
    {
        if(l[r[x]]==x)
        {
            fd(r[x],st,1,s+1);
        }
        else if(l[r[x]]==x-1)
        {
            ans+=s;
        }
        return;
    }
    if(l[r[x]]==x)
    {
        fd(r[x],st,0,s);
    }
    else if(l[r[x]]==x-1)
    {
        fd(r[x],st,1,s+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            int L,R;
            if(!l[i])
            { 
                L=1;
                R=i-1;
                while(L<=R)
                {
                    int mid=L+R>>1;
                    if(a[i]-a[mid]<=d)
                    {
                        l[i]=mid;
                        R=mid-1;
                    }
                    else
                    {
                        L=mid+1;
                    }
                }
                l[i]=i;
            }
            L=i+1;
            R=n;
            while(L<=R)
            {
                int mid=L+R>>1;
                if(a[mid]-a[i]<=d)
                {
                    r[i]=mid;
                    if(!l[mid])
                    {
                        l[mid]=i;
                    }
                    L=mid+1;
                }
                else
                {
                    R=mid-1;
                }
            }
            if(!r[i])
            {
                r[i]=i;
            }
        }
        for(int i=1;i<=n;i++)
        {
            fd(r[i],i,0,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}

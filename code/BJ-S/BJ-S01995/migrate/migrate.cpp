#include<bits/stdc++.h>
#define ll long long
const ll inf=1e18;
using namespace std;
int c,t,n,l[2000005],r[2000005];
ll d,x[2000005];
vector<int> e;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        //cout<<"n:"<<n<<'\n';
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            l[i]=i;
            r[i]=i;
            int L=1,R=i-1;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(x[i]-x[mid]<=d)  l[i]=mid,R=mid-1;
                else    L=mid+1;
            }
            L=i+1,R=n;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(x[mid]-x[i]<=d)  r[i]=mid,L=mid+1;
                else    R=mid-1;
            }
        }
        x[n+1]=inf;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            e.clear();
            e.push_back(i);
            int lst=i,N=n;
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[j-1]>d)
                {
                    N=j-1;
                    break;
                }
                if(j==n||x[j+1]-x[lst]>d)
                {
                    lst=j;
                    e.push_back(j);

                }
            }
            int cnt=0,id=1,p=0;
            for(int j=e[1]+1;j<=N;j++)
            {
                int g=e[id];
                while(id+1<e.size()&&e[id+1]<=j) id++;

                cnt=0;
                if(j==e[id])
                {
                    if(g-1>=1&&x[j]-x[g-1]<=d)  p++;
                    if(g-2>=1&&x[j]-x[g-2]<=d)  p++;
                }
                else
                {
                    if(g-1>=1&&x[j]-x[g-1]<=d)  cnt++;
                    if(g-2>=1&&x[j]-x[g-2]<=d)  cnt++;
                }

                if(p+cnt==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

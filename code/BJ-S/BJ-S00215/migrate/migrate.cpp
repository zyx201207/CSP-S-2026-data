#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
int c,t,n,nxt[MAXN+1],arry[MAXN+1],ans,tmp;
long long d,x[MAXN+1];
int main()
{
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>x[i];
                nxt[i]=lower_bound(x+1,x+i+1,x[i]-d)-x;
            }
        if(11<=c&&c<=14)
        {
            cout<<0<<'\n';
            continue;
        }
            ans=0;
            for(int i=3;i<=n;i++)
            {
                if(nxt[i]==i)
                {
                    continue;
                }
                memset(arry,0,sizeof(arry));
                arry[i]=1;
                arry[nxt[i]-1]=-1;
                tmp=nxt[i];
                for(int j=i-1;j>0;j--)
                {
                    arry[j]+=arry[j+1];
                    if(arry[j]==2)
                    {
                        ans++;
                    }
                    if(nxt[j]==j)
                    {
                        break;
                    }
                    arry[min(j-1,tmp-1)]+=arry[j];
                    arry[nxt[j]-1]-=arry[j];
                    if(j==tmp)
                    {
                        tmp=nxt[j];
                    }
                }
            }
            cout<<ans<<'\n';
    }
    return 0;
}
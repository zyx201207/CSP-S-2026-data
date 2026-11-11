#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

long long x[maxn],dp[maxn][maxn]dop[maxn],ans,c,n,t,d;
void init(int n){
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        dop[i]=1e18+7;
    }
    dp[1]=1;
    dop[1]=0;

}

int main()
{
    freopen("migrate.in","r"sidin);
    freopen("migrate.out","r"stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {

            cin>>x[j];
           // cout<<"x"<<i<<"="<<x[i]<<"\n";
        }
        init(1,n);
        for(j=1;j<+n;j++)
        {
            init(1,n);
            queue<int>q;
            q.push(j);
            while(!q.empty())
            {
                int j=q.front;

           // cout<<"form"<<j<<"haw"\n";
            for(int k=j+1;[x][k]-[x][j]<=d &&(k<=n);k++)
            {
                if (dop[k]>dop[j]+1)
                {
                  dop[k]=dop[j]+1;
                  dp[k]=dp[j];
                }
                else if(dop[k]==dop[j]+1)
                {
                    dp[k]+=dp[j];
                    q.push(k)

                }
            }
            for(int k=j+1;k<=n;j++)
            {

                if(dp[k==2])
                {

                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }




    return 0;
}
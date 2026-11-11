#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long b[5000005];
bool c[5000][5000];
bool o[5000][5000];
int u[1000000];
int ans1=0;
bool p=0;
 int c1,t,n,d,en=0,st=0;
void dfs(int num,int sum,int ans,int st)
{
    if(num==en)
    {
        int sum1=sum+(ans+d-1)/d;

        if(c[num][sum1]!=0&&p==0)
        {
        ans1+=1;
        p=1;
        return ;
        }
        c[num][sum1]=1;
        u[st]=1;
         return;
    }

    if(num+1==en)
    {

        dfs(num+1,sum+(b[num]+d+ans-1)/d,0,num);
    }
    else
    {
        dfs(num+1,sum,ans+b[num],st);
    dfs(num+1,sum+(b[num]+d+ans-1)/d,0,num);
    }


}
int main()
{
   freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(c,0,sizeof(c));
    memset(o,0,sizeof(o));
    memset(u,0,sizeof(u));
    cin>>c1>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];

        for(int i=1;i<=n;i++)b[i-1]=a[i]-a[i-1];

       for(int i=1;i<=n;i++)
       {

           for(int j=i+2;j<=n;j++)
           {
               st=i;
               en=j;
               p=0;
               dfs(i,(b[i]+d-1)/d,0,i);
               dfs(i,0,b[i],i);
               memset(c,0,sizeof(c));
               memset(u,0,sizeof(u));
           }
       }
    }
    cout<<ans1/3;
    return 0;
}

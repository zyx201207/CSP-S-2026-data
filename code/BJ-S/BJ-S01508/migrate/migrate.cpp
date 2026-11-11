#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+100;
int a[N];
int sum[N];
int dp[N];
int l;
int ans,num;
int c,t;
int n,d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            c=i;
            num=1;
            for(int j=i+1;j<=n;j++)
            {
                while(a[j]-a[l]>d)
                { 
                    num-=sum[l];
                    l++;  
                }
                if(l==j) break;
                dp[j]=dp[l]+1;
                if(num==2&&dp[j]>=2) ans++;
                sum[j]=num;
                num+=sum[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
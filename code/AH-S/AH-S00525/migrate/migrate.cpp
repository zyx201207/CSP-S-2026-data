#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &x){
    char c=getchar();
    bool fl=0;
    x=0;
    while(c<'0'||c>'9'){
        if(c=='-')fl=1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    if(fl)x=-x;
}
int n,d;
int t;
const int N=2e4+5;
int dp[N][301];
int mindis[N];
int ans;
int a[N];
int c;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        read(n);
        read(d);
        for(int i=1;i<=n;i++){
            read(a[i]);
        }
        dp[1][0]=1;
        int ans=0;
        for(int st=1;st<n;st++){
            for(int k=0;k<=n;k++)
            for(int i=st;i<=n;i++)dp[i][k]=0,mindis[i]=n;
            dp[st][0]=1;
            for(int k=1;k<n;k++){
                for(int i=st+1;i<=n;i++){
                    for(int j=i-1;j>=st;j--){
                        if(a[i]-a[j]>d)break;
                        if(dp[i][k]>2)break; 
                        dp[i][k]+=dp[j][k-1];
                    }
                    if(dp[i][k])mindis[i]=min(mindis[i],k);
                    if(dp[i][k]==2&&k==mindis[i])ans++;//cout<<st<<" "<<i<<endl;
                }
            
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
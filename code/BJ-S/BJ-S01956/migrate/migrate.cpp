#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int f=1,sum=0;
    char c=getchar();
    while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
int n,d,c,t;
int dp[5001][5001];
int dp2[5001][5001];
int a[5001];
int cnt[5001][5001];
void solve(){
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cnt[i][j]=0;
            if(i==j)continue;
            dp[i][j] = INT_MAX/3;
            dp2[i][j] = INT_MAX/3;
        }
    }
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                dp[i][j]=1;
                dp[j][i]=1;
                dp2[i][j]=1;
                dp2[j][i]=1;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp2[i][j]=min(dp2[i][k]+dp2[k][j],dp2[i][j]);
                if(dp2[i][k]+dp2[k][j]==dp[i][j]&&(i<k)&&(k<j))cnt[i][j]++;
            }
        }
    }
    long long sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt[i][j]==2)sum++;
        }
    }cout<<sum<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    while(t--)solve();
    return 0;
}

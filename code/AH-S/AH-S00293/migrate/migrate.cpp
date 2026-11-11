#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int c,t,n,cnt;
long long a[3005],dp[3005][3005],d;
void dfs(int ci,int pos,int aim){
    if(aim==pos){
        if(ci==0) cnt++;
        else return ;
    }
    if(ci==0&&aim!=pos) return ;
    for(int i=pos-1;i>=1;i--) {
        if(a[pos]-a[i]<=d) dfs(ci-1,i,aim);
        else break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        /*
        for(int i=1;i<=n;i++) dp[i][i]=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[j]-a[k]<=d) dp[i][j]+=dp[i][k];
                    else break;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]==2){
                    cnt++;
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<cnt<<endl;
        */
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int con;
                if((a[j]-a[i])%d==0) con=(a[j]-a[i])%d;
                else con=int(a[j]-a[i])%d+1;
                for(int k=1;k<=con;k++){
                    cnt=0;
                    dfs(k,j,i);
                    if(cnt==2) sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

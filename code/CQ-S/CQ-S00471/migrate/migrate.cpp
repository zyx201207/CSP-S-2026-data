#include<bits/stdc++.h>
using namespace std;
int n,d,c,t,x[5003],dis[5003][5003],ans[5003][5003],cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","r",stdin);
    cin >> c >> t;
    while(t--){
        cin >> n >>d;
        cnt=0;
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)cin >> x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)dis[i][j]=0;
                else if(abs(x[i]-x[j])<=d){
                    dis[i][j]=1;
                    ans[i][j]++;
                }else dis[i][j]=0x3f3f3f3f;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        ans[i][j]=1;
                    }else if(dis[i][j]==dis[i][k]+dis[k][j]&&(i!=j&&j!=k&&k!=i)){
                        //if(i==1&&j==3)cout << k << ":" <<endl;
                        ans[i][j]++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]==2){
                    //cout << i << " " << j<<endl;
                    cnt++;
                }
            }
        }
        cout << cnt/2 << "\n";
    }
}
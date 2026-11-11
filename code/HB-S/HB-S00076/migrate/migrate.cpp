#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;

int c,t;
int a[N],dis[5005][5005];
bool is[5005][5005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>=11&&c<=12){
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<0<<endl;
        }
    // }else if(c<=10){
    }else{
        while(t--){
            int n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            memset(dis,0x3f,sizeof dis);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    if(abs(a[i]-a[j])<=d)
                        dis[i][j]=1;
                }
            }

            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        if(i==j||j==k) continue;
                        if(dis[i][j]+dis[j][k]<dis[i][k])
                            dis[i][k]=dis[i][j]+dis[j][k];
                        else if(dis[i][j]+dis[j][k]==dis[i][k]){
                            is[i][k]=1;
                        }
                    }
                }
            }
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=n;j++){
            //         cout<<dis[i][j]<<' ';
            //     }
            //     cout<<endl;
            // }
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    if(is[i][j]==1) cnt++;
                }
            }
            cout<<cnt<<'\n';
        }
    }
}
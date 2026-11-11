#include<bits/stdc++.h>
using namespace std;
const int mxn=20006;
const int inf=INT_MAX/2;
int c,t,n,d;
int a[mxn],dis[mxn][mxn],far[mxn];
int main(){
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i;a[j]<=a[i]+d && j<=n;j++){
                dis[i][j]=1;
                far[i]=j;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dis[i][j]<<' ';
            }
            cout<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][far[i]]+dis[far[i]][j]);
                far[i]=j;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dis[i][j]<<' ';
            }
            cout<<endl;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<=n;k++){
                    if(j!=k&&dis[i][j]==dis[i][k] && dis[i][j]!=0){
                        cout<<i<<' '<<j<<' '<<k<<endl;
                        cnt++;
                    }  
                }
            }
        }
        cout<<cnt<<endl;
    }
}
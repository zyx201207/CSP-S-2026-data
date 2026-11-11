#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            int dis[n][n];
            for(int j=i+1;j<n;j++){
                if(a[j]-a[j-1]<=d){
                    if(dis[i][j]==0){
                        dis[i][j]=(a[j]-a[j-1]);
                    }else{
                        if(dis[i][j]>a[j]-a[j-1]){
                            dis[i][j]=(a[j]-a[j-1]);
                        }
                    }
                }
                cout<<dis[i][j]<<" ";
            }
        }
    }
    cout<<1<<endl;
    cout<<2<<endl;
    return 0;
}

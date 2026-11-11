#include<bits/stdc++.h>
using namespace std;
int n,d,b[10005],ans1=0,a[10005],c,t;
int dfs(int u,int ans,int v){
    if(u==v){b[ans]++;return 0;}
    if(u>v)return 0;
    int i=1;
    while(a[u+i]-a[u]<=d && u+i<=n){

        dfs(u+i,ans+1,v);
        i++;
    }
    return 0;

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    cin>>c>>t;
    while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=100;k++)b[k]=0;

            dfs(i,0,j);
            for(int k=1;k<=10;k++){
                if(b[k]>=1){if(b[k]==2){ans1++;}break;}
            }


        }
    }
    for(int i=1;i<=n;i++)a[i]=0;
    cout<<ans1<<endl;
    ans1=0;
    }
return 0;
}
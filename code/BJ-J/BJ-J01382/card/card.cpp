#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],p[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    auto f=new int[200001][3001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=n;i>=1;i--){
            if(p[a[i]]){
                for(int k=1;k<=m;k++){
                    f[i][k]=f[p[a[i]]+1][k];
                }
            }else{
                for(int k=1;k<=m;k++){
                    f[i][k]=f[i+1][k];
                }
            }
            f[i][a[i]]=1;
        p[a[i]]=max(p[a[i]],i);
    }
    for(int i=1;i<=m;i++){
        for(int j=2;j<=n;j++){
            f[1][i]+=f[j][i];
            //cout<<",,,,,,,,,,,"<<f[j][i]<<endl;
        }

        cout<<f[1][i]<<' ';
        //cout<<endl;
    }

    cout<<endl;
    return 0;
}
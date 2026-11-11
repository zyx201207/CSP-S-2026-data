#include<bits/stdc++.h>
using namespace std;
int n,m,lis[1000001],a[10001][10001],t=INT_MIN,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>lis[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                a[i][j]+=lis[j]-lis[k];
            }
            if(a[i][j]<=m&&j-i>t){
                t=j-i;
            }
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<a[i][j]<<' ';
        cout<<"\n";
    }


    cout<<t+1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000005],b[5000005],k[5000005],t[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(t[a[j]]==0){
            b[j]=a[j];
            t[a[j]]++;
        }else{
            memset(b,0,sizeof(b));
            memset(t,0,sizeof(t));
            b[j]=a[j];
            t[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j]!=0){
                k[i]++;
            }
        }

    }
    for(int i=1;i<=m;i++){
        cout<<k[i]<<" ";
    }
    return 0;
}

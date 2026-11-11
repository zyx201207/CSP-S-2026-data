#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans[m]={};
    for(int i=1;i<=n;i++){
        int c[N]={};
        for(int j=i;j<=n;j++){
            c[j-i+1]=a[j];
        }
        int f[N];
        memset(f,-1,sizeof(f));
        for(int j=1;j<=n-i+1;j++){
            if(f[c[j]]!=-1){
                for(int k=f[c[j]];k<=j;k++){
                    c[k]=-1;
                }
                f[c[j]]=-1;
            }else{
                f[c[j]]=j;
            }
        }
        for(int j=1;j<=n-i+1;j++){
            if(c[j]!=-1){
                ans[c[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

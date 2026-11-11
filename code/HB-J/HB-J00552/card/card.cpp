#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int f[500005];
int ans[500005];
int num[500005];
int n,m;
bool v[500005];
void work(int j,int k){
    int i=j;
    while(i<=n){
        if(f[i]!=-1)i=f[i];
        else ans[a[i]]+=k,i++;
    }
//    cout<<j<<'!';
//    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
//    cout<<'\n';
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(!b[a[i]]){
            b[a[i]]=i;
            f[i]=-1;
        }
        else {
            f[i]=b[a[i]];
        }
        num[a[i]]++;
    }
//    for(int i=1;i<=n;i++)cout<<f[i]<<' ';
//    cout<<'\n';
    for(int j=1;j<=n;j++){
        if(v[a[j]])continue ;
        v[a[j]]=1;
        work(b[a[j]],num[a[j]]);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}

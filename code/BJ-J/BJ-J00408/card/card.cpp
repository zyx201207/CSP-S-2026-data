/*

*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],v[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            if(v[a[i]]){
                for(int j=1;j<=m;j++) if(v[j]>v[a[i]]) v[j]=0;
            }
            v[a[i]]=i;
        }
        for(int i=1;i<=m;i++) if(v[i]) ans[i]++;
        memset(v,0,sizeof(v));
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
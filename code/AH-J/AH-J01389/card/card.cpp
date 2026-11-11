#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[500005];
int t[300005];
int cn[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]==1){
                for(int k=c[a[j]]+1;k<=j;k++){
                    t[a[k]]=0;
                }
            }
            t[a[j]]=1;
            c[a[j]]=j;
        }
        for(int i=1;i<=m;i++){
            if(t[i]){
                cn[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cn[i]<<" ";
    }
    return 0;
}

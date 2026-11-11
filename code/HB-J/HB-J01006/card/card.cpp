#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010],et[300010],o[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        et[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(et[a[j]]!=j){
                j=et[a[j]];
            }
            t[a[j]]=1;
        }
        for(int j=i;j<=n;j++){
            if(t[a[j]]==1){
                o[a[j]]++;
            }
            t[a[j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<o[i]<<" ";
    }
    return 0;
}

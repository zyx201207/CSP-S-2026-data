#include<bits/stdc++.h>
using namespace std;
int a[500005];
int nw[300005];
int ans[300005];
int mx[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(!mx[a[i]]){mx[a[i]]=i;}
        for(int j=i;j<=n;j++){
            nw[a[j]]++;
            if(j!=mx[a[j]]){
                j=mx[a[j]];
            }
        }
        for(int i=1;i<=m;i++){
            if(nw[i]>0){
                ans[i]++;
            }
            nw[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500008];
int btt[300008];
int ans[300008];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(btt,0,sizeof(btt));
        for(int j=i;j<=n;j++) btt[a[j]]++;
        for(int j=1;j<=m;j++){
            if(btt[j]!=0){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

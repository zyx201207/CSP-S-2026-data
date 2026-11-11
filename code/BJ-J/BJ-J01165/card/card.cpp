#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010];
int main(){
   freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int s;
        for(int j=n;j>=1;j--){
            for(int k=n;k>=j;k--){
                if(a[j-1]==a[k]){
                    s=j;
                }
            }
        }
    for(int j=s;j<=n;j++){
        b[a[j]]++;
    }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}

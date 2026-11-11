#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]+=i;
    }
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            bool x=0;
            if(a[i]==a[j]){
                    for(int k=j;k<i;k++) b[a[k]]--;
                    x=1;
            }
            if(x) continue;
        }
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<' ';
    return 0;
}

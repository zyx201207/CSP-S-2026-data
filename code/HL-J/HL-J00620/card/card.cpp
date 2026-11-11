#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    return 0;
}

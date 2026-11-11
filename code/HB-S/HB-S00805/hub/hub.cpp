#include<bits/stdc++.h>
using namespace std;
int a[10005][5];
void fer(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>a[i][1]>>a[i][2];
    }
    if(n&1) cout<<1<<'\n';
    else cout<<2<<'\n';
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        fer();
    }
    return 0;
}

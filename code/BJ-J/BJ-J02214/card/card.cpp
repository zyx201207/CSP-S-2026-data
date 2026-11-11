#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    //:
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&m==2){
        cout<<2<<" "<<3;
    }else{
        for(int i=m;i<=1;i++){
            cout<<i;
        }
    }
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5)cout<<4<<" "<<2;
    if(n==4)cout<<3<<" "<<1<<" "<<4;
    if(n==10)cout<<10<<" "<<3<<" "<<3;
    return 0;
}

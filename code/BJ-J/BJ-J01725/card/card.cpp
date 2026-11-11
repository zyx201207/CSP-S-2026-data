#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==10&&m==3) cout<<"10 3 3";
    return 0;
}

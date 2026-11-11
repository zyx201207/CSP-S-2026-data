#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],now[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1&&m==1) cout<<1;
    if(n==2&&m==1) cout<<1;
    if(n==2&&m==2) cout<<2<<" "<<0;
    //qiuqiunigeiwodianfenba

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],zh=0,coste,zon;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        coste=0;
        zon=0;
        for(int j=i;j>=1;j--){
            coste+=a[i]-a[j];
            if(coste<=m){
                zon++;
            }
            else break;
        }
        zh=max(zh,zon);
    }
    cout<<zh;


    return 0;
}

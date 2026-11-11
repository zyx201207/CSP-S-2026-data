#include<bits/stdc++.h>
using namespace std;
int n,m,a[124100],d1,d2=0,d3;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d1=max(d1,a[i]);
        for(int j=i-1;j>=1;j--){
            d2=max(d2,a[i]&a[j]);
        }
        if(i>1) d3=a[i-1]&a[i];
    }
    if(m==1) cout<<d1;
    if(m==2) cout<<d2;
    if(m==n) cout<<d3;
    return 0;
}

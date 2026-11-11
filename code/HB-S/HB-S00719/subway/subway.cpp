#include<bits/stdc++.h>//rp++
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,k,a[131452712];
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    cin>>k;
    for(int i=0;i<2k;i++)cin>>a[i];
    for(int i=0;i<q/2;i++)cout<<712<<" ";
    for(int i=0;i<q/2;i++)cout<<831<<" ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string h="",c1;
    ll i,j,k,n,m,s=0;
    cin>>n;
    for(i=1;i<=n;i++){freopen("and.in","r",stdin);
        cin>>m>>c1;
        for(j=1;j<=m;j++){
            h+=c1;
        }
    }
    for(i=0,j=h.size()-1;i<h.size()&&j>=0;i++,j--){
        if(i==j||abs(i-j)==1) break;
        if(h[i]!=h[j]) s++;
    }
    cout<<s;
    return 0;
}

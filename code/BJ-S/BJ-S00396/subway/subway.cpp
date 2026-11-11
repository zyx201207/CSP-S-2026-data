#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[100005],k[1000005],a[5005][5005],t[5005][5005];
bool isgood(int c){
    if(7<=c<=19||c==0){
        return true;
    }else return false;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    cout<<2*w[1];
    return 0;
}
//this font is very cute
//

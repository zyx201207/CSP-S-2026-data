#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,k;
inline void file(){freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> t;
    while(t--){
        cin >> n >> k,m=n/2;
        for(int i(1),u,v;i<n;++i) cin >> u >> v;
        if(k==n) cout << "0\n";
        else cout << ((m+2+k-1)/k)/2 << '\n';
    }
    return 0;
}
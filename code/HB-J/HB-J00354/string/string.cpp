#include<bits/stdc++.h>
using namespace std;
string p,q;
char a;
int n;
long long m,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m >> a;
        for(int i=1;i<=m;i++){
            p += a;
        }
    }
    for(long long i=p.size()-1;i>=0;i--){
        q += p[i];
    }
    for(long long i=0;i<p.size()/2;i++){
        if(p[i]!=q[i]) ans++;
    }
    cout << ans;
    return 0;
}

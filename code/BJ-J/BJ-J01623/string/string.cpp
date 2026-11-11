#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,ans,len,l,r;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int x;
        char c;
        cin >> x >> c;
        string cc(x,c);
        s += cc;len+=x;
    }
    //cout << len << endl;
    if(len % 2 == 1){
        l = r = len/2;
        l--,r++;
    }
    else{
        l = len/2-1;
        r = len /2;
    }
    while(l >= 0 && r < len){
           // cout << l << " " << r << endl;
        if(s[l] != s[r]) ans++;
        l--,r++;
    }
    //cout << l << " " << r << endl;
    cout << ans;
    return 0;
}

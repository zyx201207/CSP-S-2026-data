#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin >> n;
    string s=" ";
    for ( int i=1;i<=n;i++ ) {
        int t;
        cin >> t;
        string c;
        cin >> c;
        for ( int j=1;j<=t;j++ ) s=s+c;
    }
    int j=s.size();
    for ( int i=1;i<=(s.size()-1)/2;i++ ) {
        if ( s[i]!=s[j] ) cnt++;
    }
    cout << cnt;
    return 0;
}
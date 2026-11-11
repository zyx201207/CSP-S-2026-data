#include <bits/stdc++.h>
using namespace std;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    while (n--){
        cin>>m>>c;
        for (int i=1;i<=m;i++){
            s=s+c;
        }
    }
    int ans=0;
    for (int i=0,j=s.length()-1;i<s.length(),j>=0;i++,j--){
        if (s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}
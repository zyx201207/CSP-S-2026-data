#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
int n,a[1145140],len,ans=0;
char c[1145140];
signed main(){
    string s;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for (int i=1;i<=n;i++) for (int j=1;j<=a[i];j++) s+=c[i];
    len=s.size()-1;
    for (int i=0,j=len;i<len/2;i++,j--) 
    if (s[i]!=s[j]) ans++;
    cout<<ans;
    Please AC;
}


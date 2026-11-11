#include <bits/stdc++.h>
using namespace std;
long long n;
char c[200010];
long long num[200010];
int cnt;
long long ans;
string s="";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>n;
    for (i=1;i<=n;i++) cin>>num[i]>>c[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=num[i];j++) s+=c[i];
    s=' '+s;
    for (i=1;i<(int)s.size();i++) if (s[i]!=s[(int)s.size()-i]) ans++;
    cout<<ans/2;
    return 0;
}

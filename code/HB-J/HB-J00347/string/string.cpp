#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],pl=1,pr;
long long ll,lr,ans;
char c[N];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        s+=string(a[i],c[i]);
    }
    int l=s.size();
    for (int i=0,j=l-1;i<=j;i++,j--)
        if (s[i]!=s[j]) ans++;
    cout<<ans;
    return 0;
}

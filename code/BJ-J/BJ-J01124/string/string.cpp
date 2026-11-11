#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;

int n,a[maxn],cnt,ans;
char c[maxn];
char s[10000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s[++cnt]=c[i];
        }
    }
    for(int i=1;i<=(cnt+1)/2;i++){
        if(s[i]!=s[cnt-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}

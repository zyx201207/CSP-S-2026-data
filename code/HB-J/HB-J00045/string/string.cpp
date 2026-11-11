#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200005],ans,mx,mn=0x3f3f3f3f3f3f3f3f;
char c[200005][5];
string s;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld%s",&a[i],c[i]);
        mx=max(a[i],mx);
        mn=min(a[i],mn);
    }
    if(mx<=500) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=a[i];j++)
                s+=c[i][0];
        }
        for(int i=0,j=s.size()-1;i<=j;i++,j--) {
            if(s[i]!=s[j])
                ans++;
        }
    }
    else {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=a[i]/mn;j++)
                s+=c[i][0];
        }
        for(int i=0,j=s.size()-1;i<=j;i++,j--) {
            if(s[i]!=s[j])
                ans+=mn;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
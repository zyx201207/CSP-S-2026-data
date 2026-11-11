#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,ans,a[200001];
string s,c;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);cin>>c;
        for(int j=1;j<=a[i];j++)s+=c;
        l+=a[i];
    }
    for(int i=0;i<l;i++)if(s[i]!=s[l-i-1])ans++;
    printf("%lld",ans/2);
    return 0;
}
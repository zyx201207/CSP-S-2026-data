#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005],s[200005],t[200005];
char c[200005];
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)t[i]=t[i+1]+a[i];
    int l=1;
    int p=1,q=n;
    while(p<q){
        int m=min(s[p]-l,t[q]-l)+1;
        if(c[p]!=c[q])ans+=m;
        l+=m;
        while(l>s[p]&&p<q)p++;
        while(l>t[q]&&p<q)q--;
    }
    cout<<ans;
    return 0;
}

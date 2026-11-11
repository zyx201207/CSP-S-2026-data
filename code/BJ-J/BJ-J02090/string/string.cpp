#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,a,l,ans;
char c;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a>>c;
        for(int j=1;j<=a;++j)s+=c;
        l+=a;
    }
    for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i]!=s[j])ans++;
    }
    cout<<ans;
}
//可过五分之三

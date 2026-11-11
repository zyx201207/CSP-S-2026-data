#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans;
string c,s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)s+=c;
    }
    for(int l=0,r=s.size()-1;l<=r;l++,r--){
        if(s[l]!=s[r])ans++;
    }
    cout<<ans;
    return 0;
}

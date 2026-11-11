#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,a[N];
char c[N];
int dp[N];
int m=-1,ans=0;
string s;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0;i<m/2;i++){
        if(s[i]!=s[m-i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}

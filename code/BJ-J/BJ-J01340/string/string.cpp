#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],b[maxn],cnt,start=1e9;
char c[maxn],d[maxn];
long long sum[maxn],ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }
    s=" "+s;
    for(int i=1;i<=s.length()/2;i++){
        if(s[i]!=s[s.length()-i]){
            ans++;
            //cout<<i<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}

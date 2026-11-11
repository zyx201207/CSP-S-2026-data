#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200010];
char c[200010];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //s[i]=s[len+1-i];
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i] >> c[i];
        for(int j=1;j<=a[i];++j){
            s+=c[i];
        }
    }
    //cout << s << " ";
    ll ans=0;
    ll len=s.length();
    //cout <<len<< " ";
    if(len%2){
        for(int i=0;i<len/2;++i){
            if(s[i]!=s[len-1-i])  ans++;
        }
    }
    else{
        for(int i=0;i<=len/2-1;++i){
            if(s[i]!=s[len-1-i])  ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

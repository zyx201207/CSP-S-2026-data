#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int L=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int ans=0;
    for(int i=0;i<(L+1)/2;i++){
        if(s[i]!=s[L-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

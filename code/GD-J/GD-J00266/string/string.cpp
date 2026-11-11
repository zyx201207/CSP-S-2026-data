#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s=" ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int len=s.size()-1,ans=0;
    for(int i=1;i<=(len+1)/2;i++){
        if(s[i]!=s[len-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
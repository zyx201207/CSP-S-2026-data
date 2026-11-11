#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s,s1,s2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int x;
        char c;
        cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    for(int i=0,j=s.size()-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

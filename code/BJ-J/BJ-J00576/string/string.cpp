#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0;
string s="",sl="",sr="";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a>>c;
        while(a--) s+=char(c);
    }
    int len=s.size();
    sl=s.substr(0,len/2);
    if(len%2==1) sr=s.substr(len/2+1,len/2);
    else sr=s.substr(len/2,len/2);
    reverse(sr.begin(),sr.end());
    for(int i=0;i<=len/2;i++){
        if(sl[i]!=sr[i]) ans++;
    }
    cout<<ans;
    return 0;
}

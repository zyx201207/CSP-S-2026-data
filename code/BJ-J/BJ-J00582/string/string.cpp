#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
string s;
char c;
int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p>>c;
        while(p--) s+=c;
    }
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}

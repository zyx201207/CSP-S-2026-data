#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s=" ";
    cin>>n;
    for(int i=1,nu;i<=n;i++){
        char c;
        cin>>nu>>c;
        for(int j=1;j<=nu;j++) s+=c;
    }
    int l=s.size()-1,ans=0;
    for(int i=l/2;i>=1;i--){
        if(s[i]!=s[l-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int l;
        char c;
        cin>>l>>c;
        while(l--) s+=c;
    }
    long long len=s.size();
    long long ans=0;
    for(int i=0;i<=(len-1)/2;i++){
        if(s[i]!=s[len-1-i]) ans++;
    }
    cout<<ans;
    return 0;
}

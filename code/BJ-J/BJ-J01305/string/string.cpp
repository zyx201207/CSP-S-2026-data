#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    while(n--){
        int cnt;
        char c;
        cin>>cnt>>c;
        for(int i=1;i<=cnt;i++) s=s+c;
    }
    int ans=0;
    for(int i=0;i<=s.size()/2+1;i++){
        if(s[i]!=s[s.size()-1-i]) ans++,s[i]=s[s.size()-1-i];
    }
    cout<<ans;
    return 0;
}

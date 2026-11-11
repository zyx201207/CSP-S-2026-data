#include<bits/stdc++.h>
using namespace std;
bool t(string s){
    string b="";
    for(int i=s.size()-1;i>=0;i--){
        b+=s[i];
    }
    return b==s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s+=b;
        }
    }
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            s[i]=s[s.size()-i-1];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

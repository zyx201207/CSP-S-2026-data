#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    string t=s;
    reverse(s.begin(),s.end());
    return t==s;
}
string s;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        char c;
        cin>>t>>c;
        for(int i=1;i<=t;i++) s+=c;
    }
    if(check(s)){
        cout<<0<<'\n';
        return 0;
    }
    int mid=(s.size()+1)/2;
    int cnt=0;
    for(int i=0;i<mid;i++){
        cnt+=(s[i]!=s[s.size()-i-1]);
    }
    cout<<cnt<<'\n';
    return 0;
}
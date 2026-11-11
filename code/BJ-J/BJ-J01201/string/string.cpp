#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,s1;
    int a;
    char c;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++) s+=c;
    }
    for(int i=s.size()-1;i>=0;i--) s1+=s[i];
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s1[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string cf1(){
    int len=s.size();
    string s1="";
    for(int i=0;i<len/2;i++){
        s1+=s[i];
    }
    return s1;

}
string cf2(){
    int len=s.size();
    string s2="";
    for(int i=len-1;i>len/2+len%2;i--){
        s2+=s[i];
    }
    return s2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u;char c1;
        cin>>u>>c1;
        for(int j=1;j<=u;j++) s+=c1;
    }
    string s1=cf1(),s2=cf2();
    int ans=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]) ans++;
    }
    //cout<<s1<<' '<<s2;
    cout<<ans;
    return 0;
}
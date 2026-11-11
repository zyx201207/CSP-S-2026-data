#include<bits/stdc++.h>
using namespace std;
long long n;
string A(string s){
    if(s.size()%2==1){
        string ss="";
        for(long long i=0;i<s.size()/2;i++){
            ss+=s[i];
        }
        string sss=ss;
        ss+=s[s.size()/2];
        for(long long i=sss.size()-1;i>=0;i--){
            ss+=sss[i];
        }
        return ss;
    }else{
        string ss="";
        for(long long i=0;i<=s.size()/2;i++){
            ss+=s[i];
        }
        string sss=ss;
        for(long long i=sss.size()-1;i>=0;i--){
            ss+=sss[i];
        }
        return ss;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;char aa;
        cin>>a>>aa;
        while(a--){
            s+=aa;
        }
    }
    string ss=A(s);
    long long cnt=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]!=ss[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;

}

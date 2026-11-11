#include <bits/stdc++.h>
using namespace std;
string fz(string s){
    string a="";
    for(int i=0;i<s.size();i++){
        a[i]=s[s.size()-1-i];
    }
    return a;
}
int main(){
    long long a,cnt=0;
    string f="";
    cin>>a;
    for(int i=1;i<=a;i++){
        string s;
        long long b;
        cin>>b>>s;
        f+=b*s;
    }
    freopen("string.in","w",stdin);
    fread("string.out","r",stdout);
    string a=fz(f);
    for(int i=0;i<f.size();i++){
        if(f[i]!=a[i]){
            cnt+=1;
        }
    }
    cout<<cnt;
    return 0;

}

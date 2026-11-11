#include<bits/stdc++.h>
using namespace std;
bool cmp(string s){
    string pass="";
    bool f=true;
    int l=0,r=s.size()-1;
    for(int i=0;i<s.size();i++){
        if(s[l]!=s[r]) {
            f=false;
            break;
        }
    }
    return f;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    string pass="";
    int n;
    string z;
    while(t--) {
        cin>>n>>z;
        for(int i=0;i<n;i++) pass+=z;
    }
    bool f_pass=false;
    string pass2=pass,pass3=pass;
    long long cnt=0;
    if(cmp(pass)) cout<<cnt;
    else{
        int l=0,r=pass2.size()-1;
        for(int i=0;i<pass3.size();i++){
            if(pass2[l]!=pass2[r]) cnt++;
            r--,l++;
            if(l>=r) break;
        }
        cout<<cnt;
    }
    return 0;
}

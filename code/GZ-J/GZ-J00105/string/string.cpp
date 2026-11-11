///GZ-J00105 陈艺文
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin >>n;
    string s="";
    for(long long i=1;i<=n;i++){
        long long x;cin >>x;
        char c;cin >>c;
        for(long long j=1;j<=x;j++){
            s+=c;
        }
    }
    string s1="";
    for(long long i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }
    if(s==s1){
        cout <<0;
        return 0;
    }
    long long cnt=0;
    s1="";
    while(1){
        for(long long i=s.size()-1;i>=0;i--){
                s1+=s[i];
        }
        if(s1==s){
            break;
        }
        for(long long i=0;i<s1.size();i++){
            if(s1[i]!=s[i]){
                s1[i]=s[i];
                break;
            }
        }
        s=s1;
        s1="";
        cnt++;
    }
    cout <<cnt;
    return 0;
}

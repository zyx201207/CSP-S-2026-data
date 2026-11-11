#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;char ch;
        cin>>x>>ch;
        while(x--){
            s+=ch;
        }
    }
    int op=0,op2=0,len=s.length();
    if(s.length()%2==0){
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[len-i-1])op++;
        }
        for(int i=len/2;i<len;i++){
            if(s[i]!=s[len-i-1])op2++;
        }
    }
    else{
        for(int i=0;i<(len+1)/2-1;i++){
            if(s[i]!=s[len-i-1])op++;
        }
        for(int i=(len+1)/2;i<len;i++){
            if(s[i]!=s[len-i-1])op2++;
        }
    }
    cout<<min(op,op2);
    return 0;
}

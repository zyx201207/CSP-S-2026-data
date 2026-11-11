#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    long long n,a,cnt=0;
    string s,c;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s=s+c;
        }
    }
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

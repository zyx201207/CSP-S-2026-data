#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long n,m=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        string b;
        long long a;
        cin>>a>>b;
        for(long long j=1;j<=a;j++) s+=b;
    }
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]) m++;
    }
    cout<<m;
    return 0;
}

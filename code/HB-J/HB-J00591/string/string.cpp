#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s+=c;
            s2=c+s2;
        }
    }
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s2[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

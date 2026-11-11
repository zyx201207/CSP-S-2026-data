#include<bits/stdc++.h>
using namespace std;

long long n,x,l,ans=0;
char c;
string s="";

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(long long j=1;j<=x;j++){
            s += c;
        }
    }
    l = s.length();
    for(long long i=0;i<l/2;i++){
        if(!(s[i]==s[l-1-i])){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}

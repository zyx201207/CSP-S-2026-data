#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,len=0,ans=0;
    string s="";
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        long long a;
        string b;
        cin>>a>>b;
        for(long long j=1;j<=a;j++){
            s+=b;
            len++;
        }
    }
    for(long long i=0,j=len-1;i<=len/2-1;i++,j--){
        if(s[i]!=s[j]){
            ans ++;
        }
    }
    cout<<ans;
    return 0;
}

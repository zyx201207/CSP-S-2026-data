#include<bits/stdc++.h>
using namespace std;
string s;
char k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long i=0;
    long long x,ans=0;
    long long t;long long ma=0;
    cin>>t;
    while(t--){
        cin>>x;
        ma=ma+x;
        cin>>k;
        for(;i<ma;i++)s[i]=k;
    }
        for(long long i=0;i<ma/2;i++){
            if(s[i]!=s[ma-i-1]){
                ans++;
            }
        }
    cout<<ans;
return 0;
}

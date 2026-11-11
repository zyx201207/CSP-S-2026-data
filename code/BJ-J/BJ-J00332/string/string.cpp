#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,k;
    string s;
    char a;
    cin>>n;
    long long ans=0;
    long long tem=1;
    for(long long i=1;i<=n;i++){
        cin>>k>>a;
        for(long long j=tem;j<k+tem;j++){
        s[j]=a;
        }
        tem+=k;
        }
    for(long long i=1;i<=(tem-1)/2;i++){
        if(s[i]!=s[tem-i]){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
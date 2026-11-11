#include <bits/stdc++.h>
using namespace std ;
long long n=0,a=0,sum=0,ans=0;
string b="",c="",d="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>b;
        sum+=a;
        for(long long j=0;j<a;j++){
            c=c+b;
        }
    }
    for(long long i=sum-1;i>=0;i++){
        d=d+c[i];
    }
    for(long long i=0;i<sum;i++){
        if(d[i]!=c[i]) ans++;
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[100005]={0},sz=0,cnt=0;
    char c[100005]={0},s[100005]={0};
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(long long j=sz;j<sz+a[i];j++){
            s[j]=c[i];
        }sz+=a[i];
    }for(long long i=0;i<sz/2;i++){
        if(s[i]!=s[sz-i-1]) cnt++;
    }cout<<cnt;
    return 0;
}

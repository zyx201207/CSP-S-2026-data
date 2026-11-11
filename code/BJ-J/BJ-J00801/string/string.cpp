#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        t+=x;
        for(long long j=1;j<=x;j++){
            s+=y;
        }

    }
    for(long long i=1;i<=t/2;i++){
        if(s[i]!=s[t+1-i]) ans++;
    }
    cout<<ans;
    return 0;
}

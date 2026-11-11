#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
char s[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string ss;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(long long j=1;j<=a[i];j++){
            ss+=s[i];
        }
    }
    long long ans=0,m=ss.size()-1;
    for(long long i=0;i<(ss.size()/2);i++){
        if(ss[i]!=ss[m]) ans++;
        m--;
    }
    cout<<ans;
    return 0;
}
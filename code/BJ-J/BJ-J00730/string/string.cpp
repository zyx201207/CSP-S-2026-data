#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin >> n;
    long long a[n+1];
    char c[n+1];
    long long ans=-1;
    long long sum=0;
    for(long long i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        ans+=a[i];
        for(long long j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(long long i=0;i<=ans/2;i++){
        if(s[i]!=s[ans-i]) sum++;
    }
    cout << sum;
    return 0;
}

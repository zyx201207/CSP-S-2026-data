#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l;
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        char b;
        cin>>a[i]>>b;
        l+=a[i];
        for(long long j=1;j<=a[i];j++){
            c+=b;
        }
    }
    long long p=(l+1)/2;
    long long ans=0;
    for(long long i=p;i<l;i++){
        if(c[i]!=c[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

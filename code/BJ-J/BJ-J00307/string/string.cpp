#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5,K=2e5+5;
char c[N],f[N];
int n,a[N],x,lm,sum;
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>f[i];
        for(int j=x+1;j<=x+a[i];j++) c[j]=f[i];
        x+=a[i];
    }
    lm=ceil(x*1.00/2);
    for(int i=1;i<=lm;i++) {
        if(c[i]!=c[x-i+1]) sum++;
    }
    cout<<sum;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000020],ald[1000020];
char s[1000020];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int len=0;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        len+=a[i];
    }
    int pos=n,ans=0,sm=0;
    for(int i=1;sm<len/2;i++){
        sm+=a[i];
        while(a[i]>=a[pos]){
            a[i]-=a[pos];
            ans+=(s[i]!=s[pos])*(a[pos]);
            a[pos]=0;
            pos--;
        }
        a[pos]-=a[i];
        ans+=(s[i]!=s[pos])*(a[i]);
        a[i]=0;
    }
    cout<<ans<<"\n";
    return 0;
}
//bu xing le,tiao le 1h ,jie guo yi chong gou jiu AC le...

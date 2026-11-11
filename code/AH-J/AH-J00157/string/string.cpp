#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
string s;
char c[N];
LL n,a[N],l,cnt;
void try30(){
    for(LL i=1;i<=n;i++){
        l+=a[i];
        while(a[i]--) s+=c[i];
    }
    LL cnt=0;
    for(LL i=0;i<s.size()/2;i++)
        if(s[i]!=s[min(l-1,l+1-i)]) cnt++;
    cout<<cnt;
}
void try100(){
    if(n%2!=0)
        for(LL i=1;i<=n;i++){
            if(c[i]!=c[n+1-i]){
                cnt+=labs(a[i]-a[n+1-i]);
                if(labs(a[i]-a[n+1-i])==0) cnt+=a[i];
            }
        }
    else
        for(LL i=1;i<=n/2;i++){
            if(c[i]!=c[n+1-i]){
                cnt+=labs(a[i]-a[n+1-i]);
                if(labs(a[i]-a[n+1-i])==0) cnt+=a[i];
            }
        }
    cout<<cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    bool f=false;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(a[i]*n>10000000) f=true;
    }
    if(!f) try30();
    else try100();
    return 0;
}

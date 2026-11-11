#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,cnt;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        scanf("%lld %c",&a,&c);
        for(LL j=1;j<=a;j++){
            s+=c;
        }
    }
    LL len=s.size();
    s="0"+s;
    string l=s.substr(1,len/2),r;
    if(len%2==0)r=s.substr(len/2+1,len/2);
    else r=s.substr(len/2+2,len/2);
    reverse(r.begin(),r.end());
    for(LL i=0;i<len/2;i++){
        if(l[i]!=r[i])cnt++;
    }
    printf("%lld",cnt);
    return 0;
}

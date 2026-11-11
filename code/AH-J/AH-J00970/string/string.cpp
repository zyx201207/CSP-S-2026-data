#include<bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long bs;
long long a[200005];
char c[200005];
long long gcd(long long x,long long y){
    long long yu=x%y;
    while(yu!=0){
        x=y;
        y=yu;
        yu=x%y;
    }
    return y;
}
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1){
            bs=a[i];
        }else{
            bs=gcd(a[i],bs);
        }
        cin>>c[i];
    }
    for(long long i=1;i<=n;i++){
        a[i]/=bs;
        for(long long j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    long long l,r;
    long long len=s.size();
    if(len%2==0){
        l=len/2-1;
        r=l+1;
    }else{
        l=len/2;
        r=l;
    }
    long long num=0;
    while(0<=l && r<=len-1){
        if(s[l]!=s[r]){
            num++;
        }
        l--;
        r++;
    }
    cout<<num*bs;
    return 0;
}

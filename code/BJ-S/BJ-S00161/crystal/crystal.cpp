#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005];
long long s[10000005];
int main(){
freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}

long long cnt=0;
sort(a+1,a+n+1);
long long pingjun=a[n/2+1];
for(long long i=1;i<=n;i++){
    s[i]=abs(pingjun-a[i]);
}
sort(s+1,s+n+1);
for(long long i=1;i<=n;i++){
    if(m<s[i]) break;
    m-=s[i];
    cnt++;
}
cout<<cnt;


return 0;
}

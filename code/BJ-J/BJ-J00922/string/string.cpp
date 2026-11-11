#include<bits/stdc++.h>
using namespace std;
string a[67108483],c;
long long v,cnt=0,cn=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
cin>>v>>c;
for(long long i=cn+1;i<=cn+v;i++) a[i]=c;
cn+=v;
}
for(long long i=1;i<=cn/2;i++) if(a[i]!=a[cn-i+1]) cnt++;
cout<<cnt;
return 0;
}

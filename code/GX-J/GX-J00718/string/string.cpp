#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);

long long n,m,cnt1=0,cnt2=0;
cin>>n;
string a="",b="",c="";
for(int i=0;i<n;i++){
    cin>>m>>b;
    for (int j=0;j<m;j++){
    a+=b;
    }
}
for(long long i=a.size();i>=0;i--){
    c+=a[i];
}
for(long long i=(a.size())/2;i<a.size();i++){
       if(c[i+1]!=a[i]) cnt1++;}

for(long long i=(a.size())/2;i>=0;i--){
    if(c[i+1]!=a[i]) cnt2++;
}
if(cnt1==cnt2) cout<<cnt1;
return 0;}


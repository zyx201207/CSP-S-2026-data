#include <bits/stdc++.h>
using namespace std;
long long s[99999999];
int b[9999];
long long sum[99999999];
int x[9999];
int cnt=0;
int n,m;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>s[i];
    b[i]=s[i]%2;
    for(int j=n;j>=0;j--){
        sum[j]=b[j];
    }
    x[i]=sum[i]&sum[i+1];
    cnt=max(sum[i],sum[i+1]);
}
cout<<cnt;
return 0;}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
int i;
long long sum=0,h=a[1];
for(i=2;i<=n;i++){
    sum=sum+(a[i]-h)*(i-1);
    if(sum>m)break;
    h=a[i];
}
cout<<i-1;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long  num;
long long sum=1;
int a[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
if(n%2==0){
    num=n/2;
}
if(n%2==1){
    num=n/2+1;
}
for(int j=num+1;j<=n;j++){
    if(a[j]==a[num]){
        sum++;
    }
}
for(int i=num-1;i>=1;i--){
    a[i]+=num-a[i];
    m-=num-a[i];
    if(m<=0){
        break;
    }
    sum++;
    //cout<<sum<<endl;
    //cout<<m<<endl;
}
cout<<sum;
return 0;
}

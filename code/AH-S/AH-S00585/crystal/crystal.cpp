#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long m;
int n;
cin>>n>>m;
for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
}
long long l=0,r=m+1;
while(l<r-1){
    long long mid=(l+r)/2;
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]<mid){
            sum+=mid-a[i];
        }
    }
    if(sum>m){
        r=mid;
    }else{
        l=mid;
    }
}
int sum=0;
for(int i=1;i<=n;i++){
    if(a[i]<=l){
        sum++;
    }
}
cout<<sum;
return 0;
}
//Oct31==Dec25?

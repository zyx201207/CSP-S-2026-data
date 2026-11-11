#include<bits/stdc++.h>
using namespace std;
long long n,m,x,cost,ans,sum,len,a[1000005];

int main(){

freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1);
int l=1;
sum=a[1];
len++;
for(int r=2;r<=n;r++){
	len++;
	cost=a[r]*(r-l)-sum;
	while(cost>m){
		sum-=a[l];
		l++;
		len--;
		cost=a[r]*(r-l)-sum;
	}
	sum+=a[r];
	ans=max(len,ans);
}
cout<<ans;
return 0;
}

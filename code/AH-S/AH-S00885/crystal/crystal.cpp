#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],d[N];
int main(){    
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,mx=1,A=0,B=0;
long long m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==i){
		A++;
	}
}
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
	d[i]=a[i+1]-a[i];
}
for(int i=1;i<=n;i++){
	if(d[i]==d[i+1]){
		B++;
	}
}
if(A==n){
	int cnt=1,k=0;
	for(int i=1;i<n;i++){
		if(m>=(1+i)*i/2){
		k=i;
		}else{
			break;
		}
	}
	cout<<cnt+k;
	return 0;
}
if(B==n-2){
	int cnt=1,k=0;
	for(int i=1;i<n;i++){
		if(m-(1+i)*i/2*d[i]>=0){
			k=i;
		}else{
			continue;
		}
	}
	cout<<cnt+k;
	return 0;
}
for(int i=2;i<=n;i++){
	d[i]=d[i-1]+d[i];
}
int cnt=1,l=1,r=l+1;
for(int i=1;i<=n;i++){
	long long k=m;
	for(int j=1;j<=n;j++){
		if(k-d[j]>=0){
			cnt++;
		}else{
			mx=max(mx,cnt);
			cnt=0;
			break;
		}
	}
}
cout<<mx;
return 0;
}

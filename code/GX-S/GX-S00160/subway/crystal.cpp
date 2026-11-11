#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],c[500010],x,y;
void f1(){
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<i;j++){
			sum+=(a[i]-a[j]);
		}
		if(sum>m) break;
		ans=i;
	}
	x=ans;
}
void f2(){
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum=sum+c[i-1]*(i-1);
		if(sum>m) break;
		ans=i;
	}
	y=ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		f1();
		cout<<x;
	}
	else {
		f2();
		cout<<y;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long x[300000],n,m;
bool f(long long a,long long b){
	return a>b;
}
long long f1(){
	int z;
	for(long long i=0;i<n;i++)cin>>z;
	long long mx=x[0];
	for(int i=1;i<n;i++)mx=max(mx,x[i]);
	return mx;
}
long long f2(){
	cin>>x[0];
	long long mx=x[0],lt=0;
	for(int i=1;i<n;i++){
		cin>>x[i];
		if(x[i]>=mx){
			lt=mx;
			mx=x[i];
		}
		else if(x[i]>lt)lt=x[i];
	}
	return mx&lt;
}
long long fmn(){
	
}
long long fn(){
	for(long long i=0;i<n;i++)cin>>x[i];
	sort(x,x+n,f);
	long long ans=x[0];
	for(long long i=1;i<m;i++)ans&=x[i];
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)cout<<f1();
	else if(m==2)cout<<f2();
	else cout<<fn();
	return 0;
}

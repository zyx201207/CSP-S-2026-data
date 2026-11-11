#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[1145140],c[1145140]={0};
	cin>>n>>m;int k=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		k=m;
		for(int j=0;j<i;j++){
			if(a[j]==a[i]) c[i]++;
			if(k==0||k-a[i]+a[j]<0){
			break;
			}
			else{
		k-=a[i]-a[j];
		c[i]++;}
	}}
	sort(c,c+n);
	cout<<c[n-1]+1;
	return 0;
}

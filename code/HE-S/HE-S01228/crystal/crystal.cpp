#include<bits/stdc++.h>
using namespace std;
	int a[50005];
	int c[50005];
int aaa(int z,int m){
	int c1=z-1;
	int b=c[c1];
	int s=1;
	while(m>=b&&c1>=1){
		if(m>=b){
			c1--;
			s++;
			m-=b;
			b+=c[c1];
		}
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int zs=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=n;i>1;i--){
		int j=aaa(i,m);
		if(zs<j){
			zs=j;
		}
	}
	cout<<zs;
	return 0;
}

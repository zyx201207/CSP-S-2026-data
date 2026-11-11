#include<bits/stdc++.h>
using namespace std;
long long n,x,l=0;
char c[1000000001],y;
int hwc(char a[]){
	long long ll=0,r=l-1;
	long long h=0;
	while(ll<=r){
		if(a[ll]!=a[r])h++;
		ll++,r--;
	}
	return h;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x>>y;
		for(long long j=0;j<x;j++)c[l++]=y;
	}
	cout<<hwc(c);
	return 0;
}

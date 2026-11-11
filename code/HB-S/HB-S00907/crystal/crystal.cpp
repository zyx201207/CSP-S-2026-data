#include<bits/stdc++.h>
using namespace;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[50010]={0},cnt=1,x=0,y=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==a[1]){
		cout<<n;
	}else{
		long long d=a[0]-a[1];
		if(n%2==0){
			long long t;
			t*t=1+4*m/d;
			cout<<(t+1)/2;
		}
	}
	return 0;
}

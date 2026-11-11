#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+1];
	long long b[n+1];
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);

/*	long long l=1,r=n;
	while(1==1){
	//	cout<<l<<' '<<r<<endl;
		long long i=(l+r)/2;
		if((i-1)*a[i]-b[i-1]>=m){
			if(i+1>n){
				if(ma!=a[i])
				cout<<i;
				else{
					cout<<ma+i-1;
				}
				return 0;
			}
			if(i*a[i+1]-b[i]<=m){
				
				l=i;
			}
			else{
				if(ma!=a[i])
				cout<<i;
				else{
					cout<<ma+i-1;
				}
				return 0;
			}
		}
		else{
			
			r=i;
			if(i*a[i+1]-b[i]>m){
				cout<<i;
				return 0;
			}
			if(r==l&&r==1){
				cout<<1;
				return 0;
			}
		}
	}*/
	//	cout<<l<<' '<<r<<endl;
	
		long long ma=-99999999;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			
			long long sum=(i-j)*a[i]-b[j]+b[j-1];
			if(sum>m){
				continue;
			}
			ma=max(ma,sum);
		}
	}
	/*
	long long ma=-9;
	for(int i=1;i<=n;i++){
		long long l=1,r=i,ll,rr;
		while(1==1){
			
			long long p=(l+r)/2;
			//cout<<l<<' '<<r<<i<<endl;
			long long ans=(i-p)*a[i]-b[i-1]+b[p-1];
		//	cout<<'?'<<ans;
			if(ans>=m){
				l=p;
			}
			else{
				r=p;
			}
			if(l==r||r-l==1&&ll==l&&rr==r){
				ma=max(ma,p-l+1);
				break;
			}
			ll=l,rr=r;
		}
		
	}*/
	cout<<ma;
	return 0;
}


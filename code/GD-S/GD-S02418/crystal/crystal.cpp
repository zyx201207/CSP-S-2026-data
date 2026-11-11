#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[100001],minnumber=1000000000,mindown,ma1=-100000000,m2,maxsum=-1000000000,vis,num,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			num++;
		}
	}
	if(num==n){
		for(int i=n-1;i>=1;i++){
			if((n+1)*n/2>m){
				cout<<n;
				return 0;
			}
		}
	}
	num=0;
	cha=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]==cha){
			num++;
		}
	}
	if(num==n){
		for(int i=n-1;i>=1;i++){
			if((n+1)*n/2/cha>m){
				cout<<n;
				return 0;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			minnumber=1000000000;
			for(int j=k;j<=n;j++){
				if(a[j]<minnumber){
					mindown=j;
					minnumber=a[j];
				}
			}
			a[mindown]=a[mindown]+1;
			for(int j=1;j<=n;j++){
				for(int t=j;t<=n;t++){
					if(a[j]==a[t]){
						m2++;
					}
				}
				ma1=max(ma1,m2);
				m2=0;
			}
		}
		maxsum=max(maxsum,ma1);
	}
	cout<<maxsum;
	return 0;
}

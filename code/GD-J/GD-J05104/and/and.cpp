#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,maxx=INT_MIN,m,a[N],ct,mxin;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mxin) mxin=a[i];
	}
	if(m==1){
		cout<<mxin;
		return 0;
	}
	if(n==m){
		ct=a[1];
		for(int i=2;i<=n;i++){
			ct&=a[i];
		}
		cout<<ct;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int now;
				now=a[i]&a[j];
				if(now>maxx) maxx=now;
			}
		}
		cout<<maxx;
		return 0;
	}
	if(n<=20&&m<n){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
	}
	cout<<maxx;
	return 0;
}

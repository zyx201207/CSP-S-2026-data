#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long c[500005];
long long qi[500005];
long long qq[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		qi[i]=c[i]+qi[i-1];
		
	}
	for(int i=1;i<n;i++){
		qq[i]=qq[i-1]+c[i]*i;
	}
	int maxn=0;
	for(int i=1;i<=n-1;i++){
		int l=i,r=n-1;
		while(l<r){
			int mid=(l+r)/2;
			long long ss;
			if(i==1) ss=qq[mid];
			else ss=qq[mid]-(i-1)*qi[mid]+qq[i-2]; 
			if(ss<=m){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		long long ss;
		if(i==1) ss=qq[l];
		else ss=qq[l]-(i-1)*qi[l]+qq[i-2]; 
		if(ss>m){
			l-=1;
		}
//		cout<<l<<' ';
		maxn=max(maxn,l-i+2);
	}
	cout<<maxn;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

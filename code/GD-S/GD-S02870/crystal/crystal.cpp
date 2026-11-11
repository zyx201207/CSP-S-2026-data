#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long s=0;
long long a[500001]={};
long long v[500001]={};
int sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	v[0]=0;
	for(int i=1;i<=n;i++){
		v[i]=v[i-1]+a[i];
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)/2;
			s=a[i]*(i-mid)-v[i]+v[mid];
			if(s<=m){
				r=mid;
			}
			else if(s>m){
				l=mid+1;
			}
		}
		if(s<=m){
			sum=max(sum,(i-r));
		}
	}
	cout<<sum;
	return 0;
} 

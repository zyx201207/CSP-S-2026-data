#include<bits/stdc++.h>
using namespace std;
long long n,m,r;
long long u;
long long a[500005]={},s[500005]={};
long long q(long long w){
	long long e=m;
	while(true){
		for(long long i=0;i<n;i++){
			if(e<=0){
				return 0;
			}
			if(s[i]<w){
				s[i]++;
				e--;
			}
		}
		long long p=1;
		for(long long i=0;i<r;i++){
			if(s[i]!=s[r]){
				p=0;
			}
		}
		if(p==1){
			return 0;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long max1=-1000000000;
	for(long long i=0;i<n;i++){
		r=i;
		for(long long j=0;j<n;j++){
			s[j]=a[j];
		}
		q(a[i]);
		u=0;
		for(long long j=0;j<n;j++){
			if(s[j]==s[i]){
				u++;
			}
		}
		max1=max(max1,u);
	}
	cout<<max1;
	return 0;
}

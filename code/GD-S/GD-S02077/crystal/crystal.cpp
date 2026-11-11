#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,r=1,mx;
long long pd(long long l,long long r){
	long long s=0;
	for(int i=l;i<r;i++){
		s+=a[r]-a[i];
	}
	return s;
}
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(l<=r&&l+mx<n){
		long long s=pd(l,r);
		bool f=(s<=m);
		if(f)mx=max(r-l+1,mx);
		while(s>m){
			s-=a[r]-a[l];
			l++;
		}
		r++;
	}
	cout<<mx;
	return 0;
} 

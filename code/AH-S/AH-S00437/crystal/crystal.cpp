#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long a[N],b[N];
long long cmp(long long n,long long m,long long p){
	long long s=0,k=0,s2=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=p) b[++k]=p-a[i];
	}
	long long r=k;
	while(1){
		s+=b[r];
		if(s<=m&&r>=1) r--;
		else return k-r;
	}
}
bool cmp1(long long n){
	for(long long i=1;i<=n;i++){
		if(a[i]!=i) return 0;
	}
	return 1;
}
bool cmp2(long long n){
	long long z=a[2]-a[1];
	for(long long i=4;i<=n;i+=2){
		if(a[i]-a[i-1]!=z) return 0;
	}
	return 1;
}
bool cmp3(long long n){
	long long f=a[1];
	for(long long i=2;i<=n;i++){
		if(a[i]!=f) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);
	long long n,m,maxn=0,minn=1e18+5,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	if(cmp1(n)==1){
		long long p=0,r=0;
		while(p<=m){
			r++;
			p+=r;
		}
		if(r<n) cout<<r;
		else cout<<n;
	}
	else if(cmp3(n)==1) cout<<n;
	else if(cmp2(n)==1){
		long long p=0,r=0,k=0;
		while(p<=m){
			r+=a[2]-a[1];
			p+=r;
			k++;
		}
		if(k<n) cout<<k;
		else cout<<n;
	}
	else{
		sort(a+1,a+n+1);
		for(long long i=minn;i<=maxn;i++) ans=max(ans,cmp(n,m,i));
		if(ans<n) cout<<ans;
		else cout<<n;
	}
	return 0;
} 

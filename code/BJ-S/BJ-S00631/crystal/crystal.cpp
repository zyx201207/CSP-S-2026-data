#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,minx=1e9,maxx=-1e9,cnt=0,k[500005];
bool s(int x){
	long long sum=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			k[i]=x-a[i];
			sum+=k[i];
			cnt++;
		}
	}
	if(sum<=m){
		return 1;
	}
	for(int i=1;i<=n;i++){
		if(sum-k[i]<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minx=min(minx,a[i]);
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);
	long long l=minx,r=maxx+m;
	while(l<=r){
		long long m=(l+r)/2;
		if(s(m)){
			l=m+1;
			ans=m;
		}
		else{
			r=m-1;
		}
	}
	cout<<cnt;
	return 0;
}

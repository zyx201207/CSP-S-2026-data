#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],maxn=-1e12-1,minn=1e12+1,sum;
bool f(long long h){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(h<=a[i])break; 
		sum+=(h-a[i]);
	}
	return sum<=m;
}
long long p(long long l,long long r){
	long long mid;
	while(r>=l){
	    mid=l+(r-l-1)/2;
		if(f(mid))l=mid+1;
		else r--;
	}
	return r;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}	
	sort(a+1,a+n+1);
	long long h=p(minn,maxn);
	for(int i=1;i<=n;i++){
		if(a[i]>h){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 

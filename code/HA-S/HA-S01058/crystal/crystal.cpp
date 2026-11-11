#include <bits/stdc++.h>
using namespace std;

long long n,m,a[5000010],s[5000010],minn=LONG_LONG_MAX,maxn=LONG_LONG_MIN,maxs=LONG_LONG_MIN;
map<long long,long long> cnt,start;

long long sum(long long a,long long b){
	return s[b]-s[a-1];
}

long long fillCost(long long a,long long b,long long h){
	return h*(b-a+1)-sum(a,b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
		if (cnt.find(a[i])!=cnt.end()){
			cnt[a[i]]++;
		}else{
			cnt.insert({a[i],1});
		}
		minn=min(minn,a[i]);maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for (long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if (start.find(a[i])==start.end()){
			start.insert({a[i],i});
		}
	}
	for (long long i=minn;i<=maxn;i++){
		if (cnt.find(i)==cnt.end())continue;
		long long l=1,r=start[i]-1,mid;
		while (l<r){
			mid=(l+r)/2;
			if (fillCost(mid,start[i]-1,i)<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		maxs=max(maxs,cnt[i]+start[i]-l);
	}
	cout<<maxs;
	return 0;
}

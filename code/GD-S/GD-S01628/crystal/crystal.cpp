#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],l=1e18,r=-1e18,ans,sum;
bool ch(long long x){
	long long s=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x)s+=x-a[i];
		else break;
	}
	return s<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+1+n);
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(ch(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	for(int i=1;i<=n;i++)if(a[i]<=ans)sum++;
	cout<<sum;
}

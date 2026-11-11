#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
long long a[N];
int cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long l=0,r=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		r=max(r,a[i]);
	}
	sort(a,a+n);
	long long mid;
	long long z=0;
	while(l<=r){
		mid=l+(r-l)/2;
		int ans=0;
		z=0;
		for(int i=n-1;i>=0;i--){
			if(a[i]<=mid){
				z+=mid-a[i];
				if(z>m) break;
				ans++;
			}
		}
		cnt=max(ans,cnt);
		if(z<=m) l=mid+1;
		else r=mid-1;
		if(z<=m) l=mid+1;
		else r=mid-1;	
	}
	cout<<cnt;
	return 0;
}

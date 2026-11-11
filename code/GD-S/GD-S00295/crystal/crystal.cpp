#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,l=1e13,r=0,cnt=0;
bool check(long long mid){
	long long ans=0,c=0;
	for(int k=1;k<=n;k++){
		if(a[k]>mid)continue;
		c+=mid-a[k];
		if(c>m){
			cnt=max(cnt,ans);
			return 0;
		}
		ans++;
	}
	cnt=max(cnt,ans);
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int k=1;k<=n;k++){
    	cin>>a[k];
    	l=min(l,a[k]),r=max(r,a[k]);
	}
	sort(a+1,a+n+1);
	while(l<=r){
		long long mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<cnt;
	return 0;
} 

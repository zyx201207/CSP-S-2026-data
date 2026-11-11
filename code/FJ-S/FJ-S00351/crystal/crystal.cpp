#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt[500005];
long long a[500005],m,s[500005];
long long check(int l,int r){
	return (r-l)*a[r]-(s[r-1]-s[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	cnt[1]=ans=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt[i]=cnt[i-1]+1;
			ans=max(ans,cnt[i]);
			continue;
		}
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			long long va=check(mid,i);
			if(va<=m){
				r=mid-1;
			}else if(va>m){
				l=mid+1;
			}
		}
		cnt[i]=i-l+1;
		ans=max(cnt[i],ans); 
	}
	cout << ans;
	return 0;
}

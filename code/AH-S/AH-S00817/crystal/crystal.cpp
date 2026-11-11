#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	long long he=0;
	int l=1,r=1;
	while(r<n){
		he+=(a[r+1]-a[r])*(r-l+1);
		while(he>m && l<r){
			he-=a[r+1]-a[l];
			l++;
		}
		if(he<=m)
			ans=max(ans,r-l+2);
		r++;
	}
	cout<<ans;
	return 0;
}

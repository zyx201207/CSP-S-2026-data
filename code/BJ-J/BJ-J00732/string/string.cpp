#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	pair<int,int> a[n];
	for(int i=0;i<n;++i){
		char k;
		cin>>a[i].first>>k;
		a[i].second=k-'a';
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<r){
		int k=min(a[l].first,a[r].first);
		if(a[l].second!=a[r].second){
			ans+=k;
		}
		a[l].first-=k;
		a[r].first-=k;
		if(a[l].first<=0){
			l++;
		}
		if(a[r].first<=0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}

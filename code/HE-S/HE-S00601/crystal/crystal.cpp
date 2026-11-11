#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,res,dp[500010],mx,fi=1,ak;
vector<pair<int,int> >aa;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	res=a[1];
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=res){
			aa.push_back({ans,res});
			res=a[i];
			ans=0;
		}
		ans++;
	}
	res=0;
	ans=aa[0].first;
	n=aa.size();
	for(int i=1;i<n;i++){
		res+=(aa[i].second-aa[i-1].second)*ans; 
		while(res>m){
			res-=aa[i].second-aa[fi].second;
			ans--;
			ak++;
			if(ak==aa[fi].first){
				fi++;
				ak=0;
			}
		}
		ans+=aa[i].first;
		mx=max(ans,mx);
	}
	cout<<mx;
	return 0;
}

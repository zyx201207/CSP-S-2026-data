#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<long long>a;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;long long m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long inp;cin>>inp;a.push_back(inp);
	}
	sort(a.begin(),a.end());a.push_back(a[n-1]+1);
	int l=0,r=0;long long sy=m,h=a[1];
	while(sy and r<n){
		if(sy>=(a[r+1]-a[r])*(r+1)){
			sy-=(a[r+1]-a[r])*(r+1);
			r++;
		}
		else break;
	}
	ans=r+1;
	while(r<n){
		int nxt=upper_bound(a.begin(),a.end(),a[r+1])-a.begin()-1;
		sy-=(r-l+1)*(a[nxt]-a[r]);
		while(sy<0){
			sy+=(a[nxt]-a[l]);l++;
		}
		r=nxt;
		ans=max(ans,r-l+1);
	}
	if(ans>n)ans=n;
	cout<<ans;
	return 0;
}

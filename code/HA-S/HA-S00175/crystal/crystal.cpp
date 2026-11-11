#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long maxa=-1e18;
	long long cost=0;
	int ans=0; 
	for(int l=1,r=1;l<=n;l++){
		cost+=(l-r)*(a[l]-maxa);
		maxa=a[l];
		while(cost>m){
			cost-=(maxa-a[r]);
			r++;
		}
		ans=max(ans,l-r+1);
	}
	cout<<ans;
	return 0;
}

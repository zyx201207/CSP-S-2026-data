#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum,m;
int n,l,ans;

int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=1,l=1;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		if(l<=r){
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

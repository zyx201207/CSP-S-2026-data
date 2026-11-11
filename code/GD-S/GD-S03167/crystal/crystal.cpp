#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans=0,pre[N];
long long solve(long long x){
	int s=upper_bound(a+1,a+n+1,x)-a-1;
	int l=0,r=s+1;
	while(r-l>1){
		int mid=l+(r-l)/2;
		if(pre[s]-pre[mid-1]+(s-mid+1)*x<=m)	r=mid;
		else l=mid;
	}
	return s-r+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]-a[i];
	}
	for(int i=1;i<=n;i++){
		long long res=solve(a[i]);
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4

4 1
-1 -2 -4 -2
2
*/


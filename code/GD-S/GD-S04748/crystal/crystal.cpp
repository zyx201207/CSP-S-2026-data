#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans,minn,maxx,cnt;
bool check(int x){
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x)sum+=x-a[i],cnt++;
		if(sum<=m)ans=max(ans,cnt);
	}
	if(sum<=m){
		ans=max(ans,cnt);
		return 1;
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,r=5e5;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/

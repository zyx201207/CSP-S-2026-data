#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m,a[N];
int minn=1e18,maxn=-1e18;

int check(int x,int idx){
	int R=idx;
	int res=0,cnt=0;
	for(int i=R;i>=1;i--){
		if(res+x-a[i]>m) break;
		res+=x-a[i];
		cnt++;
	}
	return cnt;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(a[i],minn);
		maxn=max(maxn,a[i]);
	}
	if(maxn==minn){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=-1;
//	for(int i=1;i<=n;i++){
//		int res=check(a[i],i);
//		if(ans<res){
//			ans=res;
//		}else{
//			break;
//		}
//	}
	for(int i=1;i<=n;i++){
		ans=max(ans,check(a[i],i));
	}
	cout<<ans;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		a[i]-=minn;
//	}
//	maxn-=minn;
//	if(maxn==0){
//		cout<<n<<'\n';
//		return 0;
//	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
const int N=5e5+10;
int n,m,a[N];
bool check(int x){
	int now=0;
	for(int i=1;i<=x;i++){
		now+=a[x]-a[i];
	}
	if(now<=m)return 1;
	for(int i=x+1;i<=n;i++){
		now=now+x*(a[i]-a[i-1])-(a[i-1]-a[i-x]);
		if(now<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}

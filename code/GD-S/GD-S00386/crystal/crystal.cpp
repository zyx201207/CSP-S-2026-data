#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],c[N];
inline bool cmp(int x,int y){
	return x>y;
}
inline bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int z=i,y=i+x-1;
		int ans=c[y]-c[z-1]-b[z]*x;
		if(ans<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[1]-a[i];
		c[i]=b[i]+c[i-1];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}

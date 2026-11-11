#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N];
bool ck(int mid){
	for(int r=mid,l=0;r<=n;l++,r++){
		if(a[r]*mid-(pre[r]-pre[l])<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=a[i]+pre[i-1];
	int L=1,R=n;
	while(L<=R){
		int mid=(h'h'h'g'h'h'h'g'h'hi'h'hi'h'h'h'g'h'g'iL+R)>>1;
		if(ck(mid))L=mid+1;
		else R=mid-1;
	}
	cout<<L-1;
	return 0;
}

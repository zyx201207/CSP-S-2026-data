#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],pre[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int mx=0;
	for(int i=n;i>=1;i--){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r+1)>>1;
			if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m) r=mid;
			else l=mid+1;
			if(((l+r+1)>>1)==r) break;
		}
		if(a[i]*(i-l)-(pre[i-1]-pre[l-1])<=m){
			mx=max(mx,i-l+1);
		}
		else if(a[i]*(i-r)-(pre[i-1]-pre[r-1])<=m)mx=max(mx,i-r+1);
		else mx=max(mx,1);
	}
	cout<<mx;
	return 0;
}
/*
5 5
1 2 4 8 9
*/

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ma,ans,vis[N];
int p2(int y){
	int x=2,z=1;
	while(y){
		if(y&1)z*=x;
		x*=x;
		y>>=1;
	}
	return z;
}
int l2(int y){
	int z=0;
	while(y){
		y>>=1;
		z++; 
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for(int i=l2(ma);i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			cnt+=((a[j]>>(i-1))&1);
		}
		if(cnt<m)continue;
		ans+=p2(i-1);
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			vis[j]=(!((a[j]>>(i-1))&1));
		}
	}
	cout<<ans;
	return 0;
}

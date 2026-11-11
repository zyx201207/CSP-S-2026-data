#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1;
int a[500005],qz[500005];//让a[1]...a[i-1]->a[i]的代价 
int cx(int x){//让所有水晶尽可能成为a[x]的最大水晶数目 
	int f=1,l=x-1,nans=1;
	while(f<=l){
		int mid=f+l>>1,z;
		z=qz[x]-qz[mid-1]-(a[x]-a[mid-1])*(mid-1);
		if(z<=m)l=mid-1,nans=mid;//在[mid,x]花费<=m 
		else f=mid+1;
	}
	return x-nans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);//bigdata 0.2ms
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+(a[i]-a[i-1])*(i-1);
//	for(int i=1;i<=n;i++)cout<<qz[i]<<" ";
	for(int i=1;i<=n;i++)ans=max(ans,cx(i));
	cout<<ans;
	return 0;
}

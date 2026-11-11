#include<bits/stdc++.h>
#define int long long

using namespace std;
int a[500005],b[500005],sum[500005];
int ans=0;
int n,m;
bool cmp(int x,int y){
	return x<y;
}
int yidengqiu(int x){
	int cnt=0;
	memset(b,0,sizeof(b));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		if(x-a[i]<0) b[i]=1e18+5;
		else b[i]=x-a[i];
	}
	sort(b+1,b+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	int idx=n+1;
	for(int i=1;i<=n;i++){
		if(b[i]==1e18+5){
			idx=i;
			break;
		} 
		else sum[i]=sum[i-1]+b[i];
	}
	for(int i=1;i<=idx-1;i++){
		if(sum[i]<=m) cnt++;
		else break;
	}
	return cnt;
}
//bool check(int x){
//	return yidengqiu(x)>=ans;
//}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=-1e5;i<=a[n]+m;i++){
		ans=max(ans,yidengqiu(i));
	}
	cout<<ans;
	return 0;
}

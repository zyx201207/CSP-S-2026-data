#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],d[MAXN],sum[MAXN];
int n,m;
bool c(int mid){
	for(int i=1;i<=n-mid;i++){
	int summ=0,tt=1;
	for(int j=i;j<=i+mid;j++) summ+=a[i+mid]-a[j];
	if(summ<=m)	   return true;
	}
	return false;
}
bool c2(int mid){
	
}
signed main(){
	freopen("crystal.in","r",stdin);
	frropen("crysyal.out","w",stdout);
	cin>>n>>m;
	int s=0,ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1;
	int r=n;
	while(l<r){
		int mid=l+r>>1;
		if(c(mid)) l=mid;
		else r=mid-1;
	} 
	while(l<r){
		int mid=l+r>>1;
		if(c2(mid)) l=mid;
		else r=mid-1;
	} 
	cout<<l+1;
	return 0;
}     

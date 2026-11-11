#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500008],sum[500008],cnt[500008],fcnt[500008];
void work(int m){
	for(int i=n;i>=1;i--){
		if((i-1)*i/2<=m) {
			cout<<i;
			exit(0);
		}
	}
}
void work2(int m,int gc){
	int qh=0,lj=1;
	for(int i=n-1;i>=1;i--){
		qh=qh+gc*lj;
		lj++;
		if(m<qh) {
			cout<<lj-1;
			exit(0);
		} 
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		int pd1=0,pd2=0;
		int c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(a[i]==i) pd1++;
			if(i-1>=1&&a[i]-a[i-1]==c) pd2++;
		}
		if(pd1==n) work(m);
		if(pd2==n-1) work2(m,c);
		return 0;
	}
	int la=0;
	for(int j=1;j<=n;j++) {
		sum[j]=a[n]-a[j];
	}
	for(int i=n;i>=1;i--){
		cnt[i+1]=0;
		for(int j=i;j>=1;j--){
			cnt[j]=cnt[j+1]+sum[j]-sum[i];
		}
		for(int j=1;j<=i;j++){
			fcnt[j]=cnt[i-j+1];
		}
		int t=upper_bound(fcnt+1,fcnt+1+i,m)-fcnt-1;
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
5   3
*/

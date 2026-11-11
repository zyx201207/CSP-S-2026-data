#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x,d;
}a[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
bool dp[N][40];
int poww(int y){
	int num=1;
	for(int i=1;i<=y;i++){
		num*=2;
	}
	return num;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i].x=x;
		int num=0;
		while(x){
			dp[i][num]+=x%2;
			x/=2;
			num++;
		}
//		cout<<num<<' '<<a[i]<<'\n';
		a[i].d=num-1;
	}
	
	sort(a+1,a+1+n,cmp);
//	cout<<d[n-m+1]<<' '<<a[n-m+1]<<'\n';
	for(int i=n;i>n-m+1;i--){
		for(int j=a[n-m+1].d+1;j<=35;j++){
//			cout<<j<<' '<<dp[i][j]<<'\n';
			if(dp[i][j]==1){
				a[i].x-=poww(j);
				dp[i][j]=0;
			}
		}
//		if(i==n){
//			cout<<a[i]<<'\n';
//		}
	} 
	sort(a+1,a+1+n,cmp);
	int inf=LONG_LONG_MAX;
	for(int i=n;i>=n-m+1;i--){
		inf=inf&a[i].x;
//		cout<<a[i].x<<'\n';
	} 
	cout<<inf;
//	dp[1]=a[1];
//	for(int i=2;i<=n;i++){
//		for(int j=m;j>=1;j--){
//			if(j==1){
//				dp[j]=max(dp[j],a[i]);
//			}
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//		}
//	}
//	cout<<dp[m];
	return 0;
}

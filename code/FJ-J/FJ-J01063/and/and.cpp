//#include<bits/stdc++.h>
//using namespace std;
//int a[200005];
//int dp[1005];//i当前位置，j个数
//int n,m,ans=-2e9;
//bool cmp(int x,int y){
//	int xx,yy;
//	while(x){
//		if(x%2==1){
//			xx++;
//		}
//	}
//	while(y){
//		if(x%2==1){
//			yy++;
//		}
//	}
//	return xx>yy;
//}
////bool cmp(int x,int y){
////	return x>y;
////}
//int main(){
////	freopen("and.in","r",stdin);
////	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
////	sort(a+1,a+n+1,cmp);
//	sort(a+1,a+n+1,cmp);
////	for(int i=1;i<=n;i++){
////		dp[i][1]=a[i];
////	}
////	for(int i=1;i<=n;i++){
////		for(int j=m;j>=1;j--){
////			dp[j]=max(dp[j],dp[j-1]&a[i]);
////		}
////	}
////	for(int i=1;i<=n;i++){
////		cout<<dp[i][1]<<"\n";
////	}
////	for(int i=1;i<=n;i++){
////		for(int j=m;j>=i;j--){
//////			dp[i][j]=max(dp[i][j-1]&a[i],dp[i][j]);
////			for(int k=1;k<=i;k++){
////				dp[i][j]=max(dp[i][j-1]&a[i],dp[i][j]);
////			}
////		}
////	}
////	for(int i=1;i<=m;i++){
////		ans=max(ans,dp[i]);
////	}
////	cout<<ans;
////	cout<<dp[n][2];
//	for(int i=1;i<=m;i++){
//		dp[i]=dp[i-1]&a[i];
//	}
//	
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int ans=0;
void dfs(int arr,int p,int cnt,bool f){
//	cout<<arr;
	
	if(cnt>m){
//		cout<<1;
		ans=max(ans,arr);
//		cout<<cnt;
//		cout<<arr;
		return;
	}
	if(p>n)return;
	if(f==0){
		dfs(a[p],p+1,cnt+1,1);
		dfs(arr,p+1,cnt+1,0);
	}
//	cout<<(arr&a[p]);
	dfs(arr,p+1,cnt,1);
	dfs(arr&a[p],p+1,cnt+1,1);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=false;
	if(m==n){
		cin>>a[1];
		int c=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			c=c&a[i];
		}
		cout<<c;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]){
			f=true;
		}
	}
	if(!f){
		cout<<a[1];
		return 0;
	}
	dfs(0,1,1,0);
	cout<<ans;
	return 0;
}

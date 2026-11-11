#include <bits/stdc++.h>
using namespace std;
int mx=0;
int vis[200005];
int arr[200005];
bool check(int n){
	while(n%2==0) n/=2;
	return (n==1);
}
int mxbit(int n){
	int res=1;
	while(1ll*res*2<=n) res*=2;
	return res;
}
struct node{
	int num,mx;
}a[200005];
bool cmp(node a,node b){
	return a.num>b.num;
}
void dfs(int n,int k,int step,int last){
	if(step==k){
		int res=a[arr[0]].num;
		for(int i=1;i<k;i++){
			res=res&a[arr[i]].num;
		}
		mx=max(mx,res);
		return ;
	}
	for(int i=last+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			arr[step]=i;
			dfs(n,k,step+1,i);
			arr[step]=0;
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool A=true,B=true;
	if(!check(n)){
		B=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].mx=mxbit(a[i].num);
		if(a[i].num!=i-1) B=false;
		if(!check(a[i].num+1)) A=false;
	}
	sort(a+1,a+1+n,cmp);
	if(A||B){
		int res=a[1].num;
		for(int i=2;i<=m;i++) res=res&a[i].num;
		cout<<res;
		return 0;
	}else{
		dfs(n,m,0,0);
		cout<<mx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//		int mx=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				for(int k=i;k>=1;k--){
//					dp[i][j]=max(max(dp[i][j],dp[k][j]),dp[k][j-1]&a[i].num);
//				}
//			}
//			mx=max(mx,dp[i][m]);
//		}
//		cout<<mx;
//	priority_queue<int> q;
//	int mx=a[1];
//	for(int i=2;i<=n;i++){
//		dp[i]=a[i]&q.top();
//		q.push(dp[i]);
//		mx=max(mx,dp[i]);
//	}
//	cout<<mx;

#include<bits/stdc++.h>
using namespace std;
//int a[200005];
//int x[200005];
//int n,m;
//void dfs(int start,int now,int ans,int step){
//	if(step==m){
//		x[start]=ans;
//		return ;
//	}
//	ans&=a[now];
//	for(int i=now+1;i<=n-m+step;i++){
//		dfs(start,i,ans,step+1); 
//	}
//}
//int main(){
//	int maxn=0;
//	cin>>n>>m;
//	
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n-m;i++){
//		dfs(i,i+1,0,1);
//	}
//	for(int i=1;i<=n;i++){
//		maxn=max(x[i],maxn);
//	}
//	cout<<maxn;
//}
int a[200005];
int main(){
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans&=a[i];
	}
	sort(a+1,a+n+1);
	if(n==m){
		cout<<ans;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}
		cout<<maxn; 
	}
	else{
		cout<<a[n-m+1];
	} 
	return 0;
}

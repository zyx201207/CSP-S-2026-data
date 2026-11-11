#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=-1;
int a[200010];
int vis[200010];
bool cmp(int x,int y){
	return x>y;
}
//void dfs(int p,int ma){
//	if(p==m){
//		if(cnt<ma) cnt=ma;
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(vis[i]==0){
//			vis[i]=1;
//			int x=ma&a[i];
//			//cout<<ma<<endl;
//			dfs(p++,x);
//			vis[i]=0;
//		}
//	}
//}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//dfs(0,a[1]);
	sort(a+1,a+1+n,cmp);
	cnt=a[1];
	for(int i=2;i<=m;i++){
		cnt=cnt&a[i];
	}
	cout<<cnt;
	return 0;
}
//Trick||Treat!
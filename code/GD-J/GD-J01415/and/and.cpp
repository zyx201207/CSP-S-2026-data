#include<bits/stdc++.h>
using namespace std;
int a[2000006],vis[2000006];
int ans,maxn=0;
bool cmp(int x,int y){
	return x>y;
}
int yu(int x,int y){
	int cnt=1,num=0;
	while(x>0&&y>0){
		if((x%2)==1&&(y%2)==1){
			num+=cnt;
		}
		cnt*=2;
		x/=2;
		y/=2;
	}
	return num;
}
void dfs(int n,int deep){
	if(deep<=0){
		maxn=max(maxn,ans);
		return;
	}
	int oa=ans;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			ans=yu(ans,a[i]);
			vis[i]=1;
			dfs(n,deep-1);
			ans=oa;
			vis[i]=0;
		}
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n<=2000){
		for(int i=1;i<=n;i++){
			ans=a[i];
			vis[i]=1;
			dfs(n,m-1);
		}
		cout<<maxn;
	}
	else cout<<a[1];
	cout<<a[1];
}

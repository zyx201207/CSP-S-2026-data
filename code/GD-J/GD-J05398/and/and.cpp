#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,vis[N];
void dfs(int x,int sum){
	if(sum==0)return;
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	if(sum==-1){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(x+1,a[i]);
			vis[i]=0;
		}
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,(sum&a[i]));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=n-1)flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			int sum=0;
			if(i==1)sum=a[2];
			else sum=(a[1]&a[2]);
			for(int j=3;j<=n;j++){
				if(i!=j)sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,-1);
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/

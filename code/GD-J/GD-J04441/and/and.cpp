#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
int vis[N];
int arr[N];
int ans=-1e9;

void dfs(int mm){
	if(mm==m){
		int x=arr[1];
		for(int i=2;i<=m;i++){
			x=x&arr[i];
		}
		ans=max(ans,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		else{
			vis[i]=1;
			arr[mm+1]=a[i];
			dfs(mm+1);
			arr[mm+1]=0;
			vis[i]=0;
		}
	}
}

bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		dfs(0);
		cout<<ans<<'\n';
		return 0;
	}
	else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m]<<'\n';
		return 0;
	}
	return 0;
}
/*
4 2
3 15 12 12

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n,m;
int a[N];
bool vis[N];
int ans=0;
void dfs(int last,int cnt,int mm){	
	if(cnt==m){
		ans=max(mm,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(last==i) continue;
		if(vis[i]) continue;	
		vis[i]=1;
		cnt++;
		dfs(i,cnt,mm&a[i]);
		vis[i]=0;
		cnt--;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum&=a[i];
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(i,1,a[i]);
	}	
	cout<<ans;
	return 0;
}

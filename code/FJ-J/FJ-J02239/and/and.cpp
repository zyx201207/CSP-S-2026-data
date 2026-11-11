#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,int> PII;
const int N=2e5+10;
int n,m,mx=-1;
int a[N];
bool vis[N];
void dfs(int now,int cnt){//now:选数的数量 cnt:按位与总和 
	if(now==m){
		mx=max(mx,cnt);
		return;
	}
	for(int i=2;i<=n;i++){
		//选
		if(!vis[now]){
			vis[now]=1;
			dfs(now+1,cnt&a[i]);
			vis[now]=0;
		}
		//不选 
		dfs(now+1,cnt);
		vis[now]=0;
	}
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,a[n]);
	cout<<mx;
	return 0;
}

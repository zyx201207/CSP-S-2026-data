#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int ans;
int vis[N];
int n,m;
void dfs(int x,int cnt,int sum){
	//cout<<sum<<" ";
	if(vis[x]==1) return;
//当前第x个数，选择要不要按位与 以及已经选了的个数
	if(x==n+1){
		//sum=255;
		if(cnt==m){
			//cout<<1;
		ans=max(ans,sum);//找答案的最大值
		//sum=255;
	}
		return;
	}
	//if(sum==1) dfs(x+1,cnt+1,a[x]);
	dfs(x+1,cnt+1,sum&=a[x]);//选
	vis[x]=1;
	dfs(x+1,cnt,sum);//不选
	vis[x]=0;
	//return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//dfs(1,0,255);
	//cout<<(255&15);
	cout<<a[n];
	return 0;
}

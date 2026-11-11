#include<bits/stdc++.h>
using namespace std;
const int inf=1048575;
const int N=5010;

int n,m;
int a[N];
int ans=0;
bool cho[N];

void solve1(){
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,a[i]);
	cout<<res;
	return ;
}
void solve2(){
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			//cout<<i<<" "<<j<<" "
			res=max(res, ( a[i]&a[j] ) );
		}
	}
	cout<<res;
	return ;
}
void solve3(){
	int res=a[1];
	for(int i=2;i<=n;i++) res=(res&a[i]);
	cout<<res;
	return ;
}

void dfs(int x,int cnt,int tmp){
	if(cnt>m) return;
	if( x==n+1){
		if(cnt!=m) return;
		ans=max(ans,tmp);
		return; 
	}
	cho[x]=1;
	dfs(x+1, cnt+1 , (tmp&a[x]) );
	cho[x]=0;
	dfs(x+1,cnt, tmp);
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	//for(int i=1;i<=n;i++) dp[i][1]=a[i];
	if(m==1){
		solve1();
		return 0;
	}
	if(m==2){
		solve2();
		return 0;
	}
	if(m==n){
		solve3();
		return 0;
	}
	dfs(1,0,inf);
	cout<<ans;
	return 0;
}

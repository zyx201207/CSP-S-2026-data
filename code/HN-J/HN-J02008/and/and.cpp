#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int cnt,ans;
int a[N],dis[N];
int check(){
	long long all=dis[1];
	for(int i=2;i<=cnt;i++){
		all=(all&dis[i]);
	}
	return all;
}
void dfs(int Now){
	if(Now==n+1){
		if(cnt==m){
			ans=max(ans,check());
		}
		return;
	}
	cnt++;
	dis[cnt]=a[Now];
	dfs(Now+1);
	dis[cnt]=0;
	cnt--;
	dfs(Now+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

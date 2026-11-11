#include<bits/stdc++.h>
using namespace std;
long long n,m,max_v,a[200005];
bool used[200005];
void dfs(int u,int cnt){
	if(u==n+1){
		if(cnt!=m)return;
		long long tmp=0;
		for(int i=1;i<=n;i++){
			if(used[i]==1){
				if(tmp==0)tmp=a[i];
				else{
					tmp=tmp&a[i];
				}
			}
		}
		max_v=max(max_v,tmp);
		return ;
	}
	dfs(u+1,cnt);
	used[u]=1;
	dfs(u+1,cnt+1);
	used[u]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<max_v;
	return 0;
}

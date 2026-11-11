#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long maxx=0,n,m;
long long a[200001];
void dfs(int i,long long sum,int cnt){
	if(cnt==m){
		maxx=max(maxx,sum);
		return;
	}
	if(i>n){
		return;
	}
	dfs(i+1,sum,cnt);
	if(cnt<m){
		if(cnt==0){
			dfs(i+1,a[i],cnt+1);
		}else{
			dfs(i+1,sum&a[i],cnt+1);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=1,ans=0;

	dfs(1,0,0);
	cout<<maxx;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
const int INF=1e8+1;
int n,m,a[MAXN],ans=-1,times=0;
int answer[INF];
void dfs(int depth,int idx){ //depth表示深度 idx表示目前搜索到的下标 
	if(depth>m){
		times++;
		answer[times]=ans;
		return ;
	}
	if(depth==1){
		ans=a[idx];
	}
	else{
		ans=ans&a[idx];
	}
	for(int i=idx+1;i<=n;i++){
		dfs(depth+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,i);
	}
	int an=0;
	for(int i=1;i<=times;i++){
		an=max(an,answer[i]);
	}
	cout<<an;
	return 0;
}

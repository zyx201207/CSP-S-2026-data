#include <bits/stdc++.h>

using namespace std;

int n,m;

int nums[114514];
bool vis[114514]={0};

int dfs(int last,int index,int step){
	vis[index]=true;
	if(step==m){
		vis[index]=false;
		return last&nums[index];
	}
	int max_and=-114514;
	for(int i=1;i<=n;i++){
		if(!vis[i])
			max_and=max(max_and,dfs(last&nums[index],i,step+1));
	}
	vis[index]=false;
	return max_and;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>nums[i];
	int max_and=-114514;
	for(int i=1;i<=n;i++)
		max_and=max(max_and,dfs(0xFFFFFFFF,i,1));
	cout<<max_and;
}

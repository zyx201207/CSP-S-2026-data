#include <bits/stdc++.h>
using namespace std;
vector<unsigned int> a;
int n;
int m;
unsigned int ans;
vector<bool> vis;
void dfs(int have_use_num,unsigned int have_use_ans,int prev_i){
	if(have_use_num==m){//选到一种结果
		ans=max(ans,have_use_ans);//更新
		//cout<<ans<<"\n";
		return;
	}
	if(n-prev_i-1+have_use_num<m){
		//cout<<"Fail\n";
		 return;
	}//无论后面选不选，都无法用到m个
	prev_i++;
	if(!vis[prev_i]){
		vis[prev_i]=1;
		//cout<<a[prev_i]<<" ";
		dfs(have_use_num+1,have_use_ans&a[prev_i],prev_i);
		vis[prev_i]=0;
		dfs(have_use_num,have_use_ans,prev_i);
	}
}
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		vis.push_back(0);
	}
	dfs(0,0XFFFFFFFF,-1);
	cout<<ans;
	return 0;
}

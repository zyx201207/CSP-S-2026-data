#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int m;
void dfs(vector<int>& vec,long long now,int idx,int num){
	if(num==m){
		ans=max(ans,now);
		return;
	}
	for(int i=idx+1;i<vec.size();i++) dfs(vec,now & vec[i],i,num+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n>>m;
	vector<int> vec(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	for(int i=0;i<=n-m+1;i++) dfs(vec,vec[i],i,1);
	cout<<ans;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
vector<int> nums;
vector<bool> slct;
void dfs(int stp=0){
	if(stp==m){
		int lans=1;
		for(int i=0;i<n;i++){
			if(slct[i]==true) {
				if(lans==1) lans=nums[i];
				else lans&=nums[i];
			}
		} 
		ans=max(ans,lans);
		return;
	}
	for(int i=0;i<n;i++){
		if(!slct[i]){
			slct[i]=true;
			dfs(stp+1);
			slct[i]=false;
		} 
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	nums.resize(n);
	slct.resize(n);
	for(int i=0;i<nums.size();i++) cin>>nums[i];
	if(n==m){
		int lans=nums[0];
		for(int i=1;i<n;i++) lans=lans&nums[i];
		cout<<lans;
		return 0;
	}
	dfs();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

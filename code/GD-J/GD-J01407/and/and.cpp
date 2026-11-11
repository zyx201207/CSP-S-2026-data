#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,mx;
vector<int> arr;
void dfs(vector<int> v,vector<bool> dp){
	if(v.size()==m){
		int x=v[0];
		for(int i=1;i<v.size();i++)x&=v[i];
		mx=max(x,mx);
		return;
	}
	for(int i=0;i<n;i++){
		if(dp[i])continue;
		dp[i]=true;
		v.push_back(arr[i]);
		dfs(v,dp);
		dp[i]=false;
		v.pop_back();
	}
}
int main(){
	//freopen("D://down/and/and5.in","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	if(n<=20){
		vector<bool> dp(n,false);
		dfs({},dp);
		cout<<mx;
		return 0;
	}
	sort(arr.begin(),arr.end());
	int ans=arr.back();
	for(int i=n-2;i>=n-m;i--)ans&=arr[i];
	cout<<ans;
	return 0;
}
//wo shi qu

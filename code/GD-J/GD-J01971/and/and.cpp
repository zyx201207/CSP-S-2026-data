#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int>ans;
int maxs;
vector<int>num;
void dfs(int l,int now){
	if(ans.size()>=m){
//		for(auto a:ans){
//			cout<<a<<' ';
//		}
//		cout<<'\n';
		int s=num[ans[0]];
		for(int i=1;i<m;i++){
			s=(s&num[ans[i]]);
		}
		maxs=max(maxs,s);
		return;
	}else if(n-now<m-l)return;
	for(int i=now;i<n;i++){
		ans.push_back(i);
		dfs(l+1,i+1);
		ans.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		num.push_back(c);
	}
	dfs(0,0);
	cout<<maxs;
	
	return 0;
}

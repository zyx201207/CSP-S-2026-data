#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int ans;	
int n,m;
vector<int>v;
void dfs(int x,int y,int sum){
	if(x==n+2){
		return; 
	}
	if(y==m){
//		cout<<sum<<endl;
//		int e=v.size();
//		for(int i=0;i<e;i++){
//			cout<<v[i]<<" ";
//		}
//		cout<<endl;
		if(sum>ans){
			ans=sum;
			return;
		}
	}
	if(y==0){
		sum=a[x];
//		v.push_back(x);
		dfs(x+1,y+1,sum);
//		v.pop_back();
	}
//	v.push_back(x);
	
	dfs(x+1,y+1,sum&a[x]);
//	v.pop_back();
	dfs(x+1,y,sum);
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
} 

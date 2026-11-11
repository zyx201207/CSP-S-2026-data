#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int l=2e5+5;
int n,m;
ll a[l],ans;
void dfs(int x,int lt,ll y){
	if(x>=m){
		ans=max(ans,y);
//		cout<<lt<<" "<<y<<"\n";
		return ;
	}
	if(lt>=n)return ;
	for(int i=lt+1;i<=n;i++){
		if(y==0){
			dfs(x+1,i,a[i]);
		}else{
			dfs(x+1,i,y&a[i]);
		}
		dfs(x,i,y);
	}
}
int main(){
	freopen(" and.in","r",stdin);
	freopen(" and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
bool vis[M];
int l[M];
int sum[M];
void dfs(int i,int j){
	memset(vis,0,sizeof vis);
	memset(l,0,sizeof vis);
	vector<int>b;
	for(int i=1;i<=j;i++){
		if(vis[a[i]]==0){
		   b.push_back(a[i]);
		   vis[a[i]]=1;
		   l[a[i]]=b.size()-1;
		}
		else{
		   b.erase(b.begin()+l[a[i]],b.end());
		   b.push_back(a[i]);
		   l[a[i]]=b.size()-1;
		}
	}
	for(auto it:b) sum[it]++;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dfs(i,n);
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}

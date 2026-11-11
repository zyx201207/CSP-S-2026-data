#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N],maxn=-1e9;
vector<int> p;
void dfs(int step,vector<int> prt,int id){
	if(id==n+1){
		if(step==m){
			int ans=prt[0]&prt[1];
			for(int i=2;i<prt.size();i++){
				ans&=prt[i];
			}	
			maxn=max(maxn,ans);	
		}
		return;
	}
	dfs(step,prt,id+1);
	vector<int> qrt=prt;
	qrt.push_back(a[id]);
	dfs(step+1,qrt,id+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,p,1);
	cout<<maxn;
	return 0;
}

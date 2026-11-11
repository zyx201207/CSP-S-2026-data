#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> l;
int n,m;
int a[200005];
int maxk=-1;
void dfs(int p,int s){
	if(s==m){
		int res=l[0];
		for(int i=1;i<m;++i){
			res=res&l[i];
		}
		if(res > maxk){
			maxk=res;
		}
			
		for(int i=0;i<s;++i){
			l[i]=0;
		}
		
		return;
	}
	for(int i=p;i<=n;++i){
		dfs(i+1,s);
		l.push_back(a[i]);
		dfs(i,s+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<maxk;
	return 0;
}


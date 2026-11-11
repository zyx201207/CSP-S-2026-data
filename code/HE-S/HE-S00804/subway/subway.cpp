#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int c,n,m,d,q,w[N];
struct A{
	bool t[N]; 
	int a[N]; 
}s[N];
vector<int> res;
void dfs(int x,int y,int ans){	
	for (int j=1;j<=n;j++){
		if (s[x].t[j] && s[y].t[j]){		
			res.push_back(ans);
			return;
		}
	}
	for (int i=x;i<=m;i++){
		if (i==x) continue;
		for (int j=1;j<=n;j++){			
			if (s[x].t[j]==1 && s[i].t[j]==1){ 
				dfs(i,y,ans+=s[x].a[j]+s[i].a[j]);
			}
		}
	}
}
void subway(int x,int y){
	int ans=0;
	ans+=w[x]+w[y];
	res.clear();	
	dfs(x,y,0);	
	int min_=1e5;
	for (int i=0;i<res.size();i++){
		min_=min(min_,res[i]);
	}
	ans+=min_;
	cout<<ans<<endl;
}
int main(){
	int C;
	cin>>C;
	cin>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			s[x].t[i]=1; s[x].a[i]=y;
		}
	}
	for (int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		subway(x,y);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

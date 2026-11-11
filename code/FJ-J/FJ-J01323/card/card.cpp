#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,s[M],lst[M],a[N];
vector<int> v[M];
void dfs(int now){
	int l=v[now].size();
	for(int i=0;i<l;i++){
		int to=v[now][i];
		dfs(to);
		s[now]=s[now]+s[to];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
		lst[a[i]]=i;
	}
	int root=0;
	for(int i=1;i<=m;i++){
		if(s[i]==0) continue;
		if(lst[i]==n){
			root=i;
			continue;
		}
		v[a[lst[i]+1]].push_back(i);
	}
	dfs(root);
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,to[N],ans[N],mp[N],t[N];
vector<int>e[N];
void bfs(int n){
	int sum=0;
	for(int i:e[n]){
		bfs(i);
		sum+=ans[i];
	}ans[n]=sum+t[n];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mp[i];
		to[mp[i]]=-1;
	}for(int i=n;i>=1;i--){
		if(to[mp[i]]==-1){
			to[mp[i]]=mp[i+1];
			e[mp[i+1]].push_back(mp[i]);
		}
		t[mp[i]]++;
	}
	bfs(0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

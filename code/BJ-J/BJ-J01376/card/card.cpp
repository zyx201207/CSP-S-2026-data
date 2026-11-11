#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,a[500005],nxt[500005],lst[300005],tot,ans[300005],id[500005],in[300005],m;
vector<int> g[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==0){
			id[i]=a[i];
			ans[a[i]]++;
		}
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nxt[i]==0){
			if(i==n) continue;
			g[id[i]].push_back(id[i+1]);
			
			in[id[i+1]]++;
		}
		else{
			id[i]=id[nxt[i]];
			ans[id[i]]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:g[x]){
			in[y]--;
			ans[y]+=ans[x];
			if(in[y]==0) q.push(y);
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

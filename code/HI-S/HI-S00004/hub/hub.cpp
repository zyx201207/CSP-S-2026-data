#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1000001];
int num,biggestans,ans,n,k,que[1000001],d[1000001],result,bfsque[10000];
inline void dp(){
	result=0;
	memset(d,0,sizeof(d));
	for (int i=1;i<=num&&result<3;i++){
		if (d[que[i]]==0){
			d[que[i]]=1;
			result++;
			int f=1,t=0;
			bfsque[++t]=que[i];
			while (f<=t){
				int y=bfsque[f++],l=edges[y].size();
				for (int k=0;k<l;k++){
					if (d[edges[y][k]]==0){
						d[edges[y][k]]=d[y]+1;
						bfsque[++t]=edges[y][k];
					}
				}
			}
		}
	}
}
inline void bfs(){
	int ans=0;
	for (int i=1;i<=num;i++){
		memset(d,0,sizeof(d));
		int f=1,t=0;
		bfsque[++t]=que[i];
		while (f<=t){
			int y=bfsque[f++];
			int l=edges[y].size()-1;
			for (int k=0;k<=l;k++){
				if (d[edges[y][k]]==0){
					d[edges[y][k]]=d[y]+1;
					bfsque[++t]=edges[y][k];
				}
			}
		}
		for (int j=1;j<=num;j++){
			ans=max(ans,d[j]-1);
		}
	}
	biggestans=min(biggestans,ans);
}
inline void plan(int i){
	if (num==k){
		dp();
		if (result>2)return ;
		else{
			bfs();
		}
		return;
	}
	if (i==n+1||num>k)return;
	que[++num]=i;
	plan(i+1);
	num--;
	plan(i+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	biggestans=1<<30;
	ans=1<<30;
	int c,t;
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		ans=1<<30;
		num=0;
		cin>>n>>k;
		for (int i=1;i<=n-1;i++){
			int u,w;
			cin>>u>>w;
			edges[u].push_back(w);
			edges[w].push_back(u);
		}
		plan(1);
		cout<<biggestans<<endl;
	}
	return 0;
}





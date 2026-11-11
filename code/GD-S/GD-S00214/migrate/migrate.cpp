#include<bits/stdc++.h>
using namespace std;
int T,pl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&pl,&T);
	while(T--){
		int n,d,x[10001],step,cur,ans=0;
		vector<int> node[1001];
		pair<int,int> fin[100001],EMPTY=make_pair(INT_MAX,0),flag=make_pair(-1,-1);
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;++i) scanf("%d",&x[i]),fin[i]=EMPTY;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]>d) break;
				node[i].push_back(j);
			}
		for(int i=1;i<n;++i){
			queue<int> bfs;
			bfs.push(i),bfs.push(-1),step=1;
			while(!bfs.empty()){
				cur=bfs.front(),bfs.pop();
				if(cur==-1){
					++step;
					if(bfs.empty()) break;
					bfs.push(-1);
					continue;
				}
				for(auto it:node[cur])
					if(fin[it]==EMPTY||fin[it].first==step){
						fin[it].first=step,++fin[it].second;
						bfs.push(it);
					}
			}
			for(int j=i+1;j<=n;fin[j++]=EMPTY)
				if(fin[j].second==2) ++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
} 

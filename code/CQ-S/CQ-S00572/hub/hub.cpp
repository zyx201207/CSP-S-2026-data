#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mn=1000003;
	struct edge{
		int x,y;
	}e[mn];
	vector<int>sons[mn];
	int n,k,d[mn],md,mi;
	void bf(){
		mi=214748364;
		for(int i=1;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k)
				continue;
			int cnt=0;
			for(int j=1;j<n;j++)
				if((i&(1<<(e[j].x-1)))&&(i&(1<<(e[j].y-1))))
					cnt++;
			if(cnt!=k-2)
				continue;
			queue<int>q;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					d[j]=0;
					q.push(j);
				}
				else
					d[j]=214748364;
			}
			while(q.size()){
				int x=q.front();
				q.pop();
				for(int i=0;i<sons[x].size();i++)
					if(d[sons[x][i]]>d[x]+1){
						d[sons[x][i]]=d[x]+1;
						q.push(sons[x][i]);
					}
			}
			int now=0;
			for(int j=1;j<=n;j++)
				now=max(now,d[j]);
			mi=min(mi,now);
		}
		printf("%d\n",mi);
	}
	void getd(int x,int fa){
		d[x]=0;
		for(int i=0;i<sons[x].size();i++){
			if(sons[x][i]==fa)
				continue;
			getd(sons[x][i],x);
			if(d[sons[x][i]]+1>d[x]){
				md=max(md,d[x]+d[sons[x][i]]);
				d[x]=d[sons[x][i]]+1;
			}
		}
	}
	int main(){
		int sc,tc;
		scanf("%d%d",&sc,&tc);
		while(tc--){
			scanf("%d%d",&n,&k);
			for(int i=1;i<n;i++){
				scanf("%d%d",&e[i].x,&e[i].y);
				sons[e[i].x].push_back(e[i].y);
				sons[e[i].y].push_back(e[i].x);
			}
			if(n<=20)
				bf();
			else
//				if(k==2){
//					md=0;
//					getd(1,0);
//					printf("%d\n",md/3);
//				}
//				else
					bf();
			for(int i=1;i<=n;i++)
				sons[i].clear();
		}
		return 0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	estidi::main();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int>v[1000009];
struct node{
	int f,x,s;
};queue<node>q;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
//		cout<<1; 
		int n,k,ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int u,w;
			scanf("%d%d",&u,&w);
			v[u].push_back(w);
			v[w].push_back(u);
		}
		for(int i=1;i<=n;i++){
			int cnt=k-1,max1=0,max2=0;
			q.push({0,i,0});
			while(!q.empty()){
				node nown=q.front();
				q.pop();
				max2=max1;
				max1=nown.s;
				for(int j=0;j<v[nown.x].size();j++){
					if(cnt==0)break;
					if(v[nown.x][j]!=nown.f&&cnt!=0){
						q.push({nown.x,v[nown.x][j],nown.s+1});
						cnt--;
					}
				} 
			}
			ans=min(ans,max1+max2);
		}
		printf("%d\n",ans);
	}
	return 0;
} 

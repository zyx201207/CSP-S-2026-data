#include<bits/stdc++.h>
using namespace std;
const int N=0x3f3f3f3f;
int fa[101];
int que(int i){
	if(fa[i]==0){
		return i;
	}else{
		fa[i]=que(fa[i]);
		return fa[i];
	}
}
bool ro[101];
int noc,noh;
int unite(int a,int b){
	fa[que(a)]=que(b);
	return 0;
}
bool mp[101][101];
int dist[101][101];
long long sol(){
	for(int k=1;k<=noc;k++){
		for(int i=1;i<=noc;i++){
			for(int j=1;j<=noc;j++){
				if(i==j){
					dist[i][j]=0;
				}else{
					dist[i][j]=min(dist[i][j],mp[i][k]+mp[k][j]);
				}
			}
		}
	}
	int res=0;
	for(int i=1;i<=100;i++){
		if(ro[i]==1){
			int cnt=0;
			queue<int> proa;
			for(int j=1;j<=noc;j++){
				if(fa[j]==i){
					proa.push(j);
					cnt++;
				}
			}
			stack<int> prob;
			stack<int> proc;
			if(cnt<noh){
				continue;
			}
			int le=0;
			for(int j=1;j<=cnt*noh;j++){
				for(int e=1;e<=noh;e++){
					prob.push(proa.front());
					proa.push(proa.front());
					proa.pop();
				}
				while(!prob.empty()){
					int a;
					a=prob.top();
					prob.pop();
					stack<int> te;
					while(!prob.empty()){
						int b=prob.top();
						if(mp[a][b]!=0){
							le=max(le,dist[a][b]);
						}
						te.push(b);
					}
					while(!te.empty()){
						prob.push(te.top());
						te.pop();
					}
				}
			}
			res=min(le,res);
		}
	}
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tidx,task;
	cin>>tidx>>task;
	for(int t=1;t<=task;t++){
		cin>>noc>>noh;
		memset(mp,0x3f,sizeof(mp));
		//memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=noc-1;i++){
			int a,b;
			cin>>a>>b;
			mp[a][b]=1;
			mp[b][a]=1;
		}
		memset(ro,0,sizeof(ro));
		for(int i=1;i<=noc;i++){
			ro[que(i)]=1;
		}
		cout<<sol();
	}
}

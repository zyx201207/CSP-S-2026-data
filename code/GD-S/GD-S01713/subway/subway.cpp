#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int mp[505][20005];
//int t[505][20005];
int w[500005];
struct nod{
	int l,t;
};
struct cmp{
	bool operator()(nod a,nod b){
		return a.t<b.t;
	}
};
priority_queue<nod,vector<nod>,cmp>lu;
int L[505];
bool v[505];
int cnt=0;
void dfs(int nod,int sam){
	
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a,T;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a>>T;
			mp[i][a]=T;
			mp[0][a]++;
			//t[i][a]=T;
		}
	}
	for(int i1=1;i1<=q;i1++){
		memset(L,0x7f,sizeof(L));
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			lu.push((nod){i,mp[i][x]});
		}int k=1;
		while(k<n){
			
			nod q=lu.top();
			lu.pop();
			v[q.l]=1;
			for(int i=1;i<=m;i++){
				if(mp[q.l][i]){
					for(int j=1;j<=n;j++){
						if(mp[j][i]&&j!=q.l){
							L[j]=min(L[j],q.t+mp[q.l][i]+mp[j][i]);
							
							
						}
					}
				}
				
			}
			k++;
		}

		
	}
}

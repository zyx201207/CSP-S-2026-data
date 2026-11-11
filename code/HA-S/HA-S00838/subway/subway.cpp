#include<bits/stdc++.h>
using namespace std;
struct noot{
	int k;
}line[505];
vector<int>z[500005];
vector<int>jd;
int c,n,m,d,q;
int w[500005];
int jdt[1005][1005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			jdt[i][j]=1<<30;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>line[i].k;
		if(line[i].k==2){
			int u,t1,v,t2;
			cin>>u>>t1>>v>>t2;
			jdt[u][v]=min(jdt[u][v],t1+t2);
			jdt[v][u]=jdt[u][v];
		}
	}
	/*jd.push_back(0);
	for(int i=1;i<=m;i++){
		for(int k1=0;k1<z[i].size();k1++){
			for(int k2=k1;k2+1<z[i].size();k2++){
			    if(z[i][k2]>z[i][k2+1]) swap(z[i][k2],z[i][k2+1]);
			}
		}
		if(z[i].size()>=2) jd.push_back(i);
	}
	for(int i=0;i<jd.size();i++){
		for(int j=i+1;j+1<jd.size();j++){
			int u=jd[i];
			int v=jd[j];
			for(int l=0;l<z[u].size();){
				for(int r=0;r<z[v].size();){
					if(z[u][l]==z[v][r]) {
						jdt[u][v]=min(jdt[u][v],line[z[u][l]].t+line[z[v][r]].t[]);
						jdt[v][u]=jdt[u][v];
					}else if(z[u][l]>z[v][r]) r++;
					else l++;
				}
			}
		}
	}*/
	for(int k=1;k<=m;k++){
		for(int u=1;u<=m;u++){
			for(int v=1;v<=m;v++){
				if(u==v||v==k) continue;
				if(jdt[u][k]!=(1<<30)&&jdt[k][v]!=(1<<30))jdt[u][v]=min(jdt[u][v],jdt[u][k]+jdt[k][v]);
				jdt[v][u]=jdt[u][v];
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+jdt[u][v]+w[v]<<endl;
	}
	return 0;
}


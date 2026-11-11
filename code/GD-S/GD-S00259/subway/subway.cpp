#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005],c[20005],d[20005];
bool flag[20005];
struct node{
	int t,p;
};
vector<int> g[20005];
int BFS(int st,int ed){
	memset(flag,0,sizeof(flag)); 
	int mn=INT_MAX;
	queue<node> q;
	q.push({st,b[1]});
	flag[st]=1;
	while(!q.empty()){
		node tc=q.front();
		q.pop();
		if(tc.t==ed){
			mn=min(mn,tc.p);
		}else{
			int f=g[tc.t].size();
			for(int i=0;i<f;i++){
				if(flag[g[tc.t][i]]==0){
					q.push({g[tc.t][i],tc.p+b[g[tc.t][i]]});
					flag[g[tc.t][i]]=1;
				}
			}
		}
	}
	return mn;
}
int jtk[20005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c1,n,m,d1,q;
	cin>>c1>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>c[j]>>d[j];
			if(j!=1){
				b[c[j]]+=d[1];
				b[c[j]]+=d[j];
			}
			if(jtk[c[j]]!=0)jtk[c[j]]=2;
			else jtk[c[j]]=1;
			if(j!=1){
				for(int k=1;k<=m;k++){
					if(flag[i]==1){
						g[c[k]].push_back(c[j]);
						g[c[j]].push_back(c[k]);
					}
				}
				g[c[1]].push_back(c[j]);
				g[c[j]].push_back(c[1]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		cout<<BFS(st,ed)+a[st]+a[ed]<<endl;
	}
	return 0;
}//Oct31==Dec25?
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2

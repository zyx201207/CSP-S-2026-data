#include<bits/stdc++.h>
using namespace std;
int n;
long long x[200010],f1[5010][5010],d,f[5010][5010];
int vis[5010];
vector<int>v[5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j)
				if(max(x[i]-x[j],x[j]-x[i])<=d)v[j].push_back(i);
			}
		int k,k1;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1e18,f1[i][j]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)vis[j]=0;
			queue<int>q,q1;
			q.push(i);
			q1.push(0);
			f[i][i]=0;
			while(!q.empty()){
				k=q.front();
				q.pop();
				k1=q1.front();
				q1.pop();
				if(k1>f[i][k]&&!vis[k])continue;
				vis[k]=1;
				for(int j:v[k]){
					if(f[i][j]>f[i][k]+1){
						f[i][j]=f[i][k]+1;
						f1[i][j]=0;
						q.push(j);
						q1.push(f[i][j]);
					}
					if(f[i][j]==f[i][k]+1){
						f1[i][j]+=f1[i][k]; 
					}
				}
			}
		}
		long long ret=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			if(i<j)ret+=(f1[i][j]==2&&f[i][j]!=1e18);
		}
		cout<<ret<<"\n";
	}
	return 0;
}

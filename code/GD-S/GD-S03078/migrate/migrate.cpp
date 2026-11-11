#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],sum;
vector<int>g[2000005];
bool BFS(int x,int y,int s){
	queue<pair<int,int> >q;
	q.push({x,s});
	int v[2000005]={0};
	v[x]=1;
	int fl=0,ss=0;
	while(q.size()){
		x=q.front().first,s=q.front().second;
		q.pop();
		if(ss&&ss!=s){
			return fl==2;
		}if(x==y){
			ss=s;
			fl++;
			continue;
		}for(int i=0;i<g[x].size();i++){
			if(!v[g[x][i]]){
				if(g[x][i]!=y){
					v[g[x][i]]=1;
				}q.push({g[x][i],s+1});
			}
		}
	}return fl==2;
}bool chk(){
	int d=x[2]-x[1];
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=d){
			return false;
		}
	}return true;
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			fill(g[i].begin(),g[i].end(),0);
		}if(n<=9){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j&&abs(x[i]-x[j])<=d){
						g[i].push_back(j);
					}
				}
			}for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(BFS(i,j,0)){
						sum++;
					}
				}
			}cout<<sum<<endl;
		}else{
			cout<<0<<endl;
		}
	}
}

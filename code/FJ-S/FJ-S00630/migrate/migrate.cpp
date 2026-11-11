#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,js=0;
long long d;
long long x[2000005];
int v[2000005];
vector<int>g[2000005];
queue<int>q;
bool bfs(int s,int f){
	//cout<<s<<" "<<f<<'\n';
	while(!q.empty()){
		q.pop();
	}
	for(int i=0;i<=n;i++){
		v[i]=-1;
	//	cout<<v[i]<<' ';
	}
	//cout<<'\n';
	v[s]=0;
	q.push(s);
	int minn=1e9;
	int cnt=0;
	while(!q.empty()){
		int d=q.front();
		q.pop();
		//cout<<d<<"\n";
		if(d==f){
			if(minn=1e9){
				minn=v[d];
			}
			if(v[d]==minn){
				cnt++;
			}
		}
		int o=g[d].size();
		//cout<<"len "<<o<<'\n';
		for(int i=0;i<o;i++){
		//	cout<<"v "<<v[g[d][i]]<<"\n";
			if(v[g[d][i]]==-1 or v[g[d][i]]==v[d]+1){
			
		//		cout<<"t"<<'\n';
				v[g[d][i]]=v[d]+1;
				q.push(g[d][i]);
			}
		}
	}
	//cout<<cnt<<"\n";
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		js=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]+d>=x[j]){
					//cout<<x[i]<<' '<<x[j]<<"\n";
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j)){
					js++;
				}
			}
		}
		cout<<js<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/


#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,y,mi=-1;
int w[500005];
vector<int>v[505];
int t[505][505];
bool o[505];
void g(int x,int s){
	o[x]=true;
	if(x==y)mi=min(mi,s);
	for(auto i:v[x]){
		cout<<i;
		if(o[i])continue;
		s+=t[i][x]+w[i]+w[x];
		g(i,s); 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	while(n--){
		int k,u[1005],ti;
		bool b=false;
		cin>>k;
		while(k--){
			cin>>u[k]>>ti;
			if(b){
				v[u[k+1]].push_back(u[k]);
				v[u[k]].push_back(u[k+1]);
				t[u[k]][u[k+1]]=t[u[k+1]][u[k]]=ti;
			}
			b=true;
		}
	}
	while(p--){
		int x;
		cin>>x>>y;
		long long h=0;
		for(int i=x;i<=y-1;i++){
				h+=t[i][i+1];
		}
		cout<<h+w[x]+w[y]<<endl;
	}
	return 0;
} 

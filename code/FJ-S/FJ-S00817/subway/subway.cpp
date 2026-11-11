#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
struct node{
	int v,w;
};
std::vector<node> f[5000005];
long long n,m,d,q,c,l[5000005];
long long di[5000005];
bool inq[5000005];
int spfa(int s,int e){
	std::queue<int> q;
	for(int i=0;i<=(3*m+m*d);i++){
		di[i]=0x3f3f3f3f3f3f3f3f;
		inq[i]=0;
	}
	di[s]=0;
	inq[s]=1;
	q.push(s);
	while(!q.empty()){
		int top=q.front();
		
		//std::cout<<top<<' '<<'\n';
		q.pop();
		inq[top]=0;
		for(int i=0;i<f[top].size();i++){
			int v=f[top][i].v,w=f[top][i].w;
			if(di[v]>di[top]+w){
				//std::cout<<top<<' '<<v<<' '<<di[top]+w<<' ';
				di[v]=di[top]+w;
				if(!inq[v]){
					//std::cout<<'.';
					inq[v]=1;
					q.push(v);
				}
				//std::cout<<'\n';
			}
		}
	}
	return di[e];
}
int main(){
	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int t;
		std::cin>>t;
		f[i].push_back({i+m,t});
		f[i+m].push_back({i,t});
	}
	for(int i=1;i<=n;i++){
		int k,ca=-1;
		std::cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			std::cin>>a>>t;
			l[a]++;
			f[a+2*m+(a-1)*d+l[a]].push_back({a+m,t});
			f[a+m].push_back({a+2*m+(a-1)*d+l[a],t});
			if(ca!=-1){
				f[a+2*m+(a-1)*d+l[a]].push_back({ca+2*m+(ca-1)*d+l[ca],0});
				f[ca+2*m+(ca-1)*d+l[ca]].push_back({a+2*m+(a-1)*d+l[a],0});
			}
			ca=a;
		}
	}
	/*
	for(int i=1;i<=100;i++){
		std::cout<<i<<"|";
		for(int j=0;j<f[i].size();j++){
			std::cout<<f[i][j].v<<' '<<f[i][j].w<<' ';
		}
		std::cout<<'\n';
	}
	*/
	for(int i=1;i<=q;i++){
		int x,y;
		std::cin>>x>>y;
		//std::cout<<x;
		std::cout<<spfa(x,y)<<'\n';
	}
	return 0;
}

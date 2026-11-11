#include <bits/stdc++.h>
using namespace std;
const long long N=505,M=5000005;
long long w[M],dst[M];
bool vis[M];
struct Node{
	long long to,tm,ln;
};
vector<Node>G[M];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c;cin>>c;
	long long n,m,d,q,s,t;cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		long long k;cin>>k;
		long long a1,t1,b1,s1;
		for(int j=1;j<=k;j++){
			if(j==1){
				cin>>a1>>t1;
				continue;
			}
			cin>>b1>>s1;
			Node tmp;
			tmp.to=b1;tmp.tm=t1+s1;tmp.ln=i;
			G[a1].push_back(tmp);
			tmp.to=a1;
			G[b1].push_back(tmp);
			a1=b1,t1=s1;
		}
	}
	//cout<<"ok";
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		memset(vis,0,sizeof(vis));
		memset(dst,0,sizeof(dst));
		
		queue<long long>q;q.push(s);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto v:G[u]){
				if(!vis[v.to]){
					long i=v.to,cd=v.tm,line=v.ln;
					vis[i]=1;
					if(dst[i]==0){
						dst[i]=dst[u]+cd;
						vis[i]=0;
					}
					if(dst[i]>dst[u]+cd){
						dst[i]=dst[u]+cd;
					}
					q.push(i);
					cout<<i<<" "<<dst[i]<<endl;
				}
			}
		}
		
		cout<<w[s]+w[t]+dst[t]<<endl;
	}

	return 0;
} 

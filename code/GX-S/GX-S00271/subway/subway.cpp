#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,T,w[500001],dis[1001][1001],dis2[6001];
vector<int> ve1[500001];
vector<pair<int,int> > ve[6001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	if(c<=6&&c){
	}else if(7<=c&&c<=11){
		for(int i=1;i<=m;++i){ 
			for(int j=1;j<=m;++j) if(i!=j) dis[i][j]=1e15;
		}
		for(int i=1;i<=n;++i){
			int k,a1,t1,a2,t2;
			cin>>k>>a1>>t1;
			if(k==1) continue;
			cin>>a2>>t2;
			dis[a1][a2]=min(dis[a1][a2],t2+t1);
			dis[a2][a1]=min(dis[a2][a1],t1+t2);
		}
		for(int k=1;k<=m;++k){
			for(int i=1;i<=m;++i){
				for(int j=1;j<=m;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
		while(q--){
			int x,y;cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<'\n';
		}
	}else if(12<=c<=19||!c){
		//cout<<"start:"<<endl;
		for(int i=1;i<=n;++i){
			int k,la=-1,a,t;cin>>k;
			//if(k==1) continue;
			while(k--){
				cin>>a>>t;
				T=t;
				ve1[a].push_back(i);
			}
		}
		//cout<<"ok0"<<endl;
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;++i) dis[i][i]=0;
		for(int i=1;i<=m;++i){
			for(int j:ve1[i]){
				for(int k:ve1[i]) dis[j][k]=dis[k][j]=2*T;
			}
		}
		//cout<<"ok1"<<endl;
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
		//cout<<"ok2"<<endl;
		while(q--){
			int x,y,ans=1e15;cin>>x>>y;
			bool f=0;
			for(int i:ve1[x]){
				for(int j:ve1[y]) f|=(i==j),ans=min(ans,dis[i][j]);
			}
			cout<<ans+w[x]+w[y]+2*T*!f<<'\n';
		}

	}
	return 0;
}

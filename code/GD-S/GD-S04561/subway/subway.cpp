#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,c,w[1010],t[1010][1010],dis[1010][1010];
vector<vector<long long>> v(1010);
bool ji[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		long long k;
		cin>>k;
		long long v1,t1;
		cin>>v1>>t1;
		for(int i=2;i<=k;i++){
			long long v2,t2;
			cin>>v2>>t2;
			v[v1].push_back(v2);
			t[v1][v2]==0 ? t[v1][v2]=t1+t2 : t[v1][v2]=min(t[v1][v2],t1+t2);
			v2=v1;
			t2=t1;
		}
	}
	
	for(int i=1;i<=n;i++){
		ji[i][i]=1;
		priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> d;
		for(int j=0;j<v[i].size();j++){
			long long z=t[i][v[i][j]],zz=v[i][j];
			d.push({z,zz});
			dis[i][v[i][j]]=t[i][v[i][j]];
		}
		dis[i][i]=0;
		while(!d.empty()){
			long long s=d.top().second;
			d.pop();
			if(ji[i][s])continue;
			for(int k=0;k<v[s].size();k++){
				long long z=t[s][v[s][k]],zz=v[s][k];
				d.push({z,zz});
				if(dis[i][v[s][k]]==0){
					dis[i][v[s][k]]=t[s][v[s][k]]+dis[i][s];
				}else{
					dis[i][v[s][k]]=max(dis[i][v[s][k]],t[s][v[s][k]]+dis[i][s]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		long long s,e;
		cin>>s>>e;
		cout<<dis[s][e]+w[e]+w[s]<<endl;
	}
	return 0;
}

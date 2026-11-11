#include<bits/stdc++.h>
using namespace std;

//¿ª longlong!!!!! 

long long inf=(1ll<<53);

long long c,n,m,d,q;
struct road{
	long long t,time;
};
vector<road> map0[500005];
long long map1[505][505];
long long dis0[500005];

long long dis1[505][505];

void floyd(){
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			for(long long k=0;k<n;k++){
				dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i<505;i++){
		for(long long j=0;j<505;j++){
			map1[i][j]=inf;
			if(i==j){
				map1[i][j]=0;
			}
		}
	}
	
//	cout<<inf<<endl;
	for(long long i=1;i<=m;i++){
		cin>>dis0[i];
	}
	
	long long z,t,time;
	for(long long i=0;i<n;i++){
		cin>>z;
		for(long long j=0;j<z;j++){
			cin>>t>>time;
			map0[t].push_back({i,time});
		}
	}
	
	//test program,shuoldn't be used
//	for(int i=0;i<m;i++){
//		for(int j=0;j<map0[i].size();j++){
//			cout<<i<<' '<<map0[i][j].t<<' '<<map0[i][j].time<<'\n';
//		}
//	}
	
	for(long long i=0;i<m;i++){
		for(long long j=0;j<map0[i].size();j++){
			for(long long k=0;k<map0[i].size();k++){
				map1[map0[i][j].t][map0[i][k].t]=min(map1[map0[i][j].t][map0[i][k].t],map0[i][j].time+map0[i][k].time);
			}
		}
	}
	
	
	
	for(long long i=0;i<505;i++){
		for(long long j=0;j<505;j++){
			dis1[i][j]=map1[i][j];
		}
	}
	
	floyd();
	//test program,shuoldn't be used
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dis1[i][j]<<'\n';
//		}
//	}
	
	long long st,en,a0,b0,dis_a,dis_b;
	long long dist=inf;
	for(long long i=0;i<q;i++){
		dist=inf;
		cin>>st>>en;
		for(long long j=0;j<map0[st].size();j++){
			for(long long k=0;k<map0[en].size();k++){
				a0=map0[st][j].t;
				b0=map0[en][k].t;
				dis_a=map0[st][j].time;
				dis_b=map0[en][k].time;
				dist=min(dist,dis_a+dis_b+dis1[a0][b0]);
			}
		}
		cout<<dist+dis0[st]+dis0[en]<<'\n';
	}
	
    return 0;
}















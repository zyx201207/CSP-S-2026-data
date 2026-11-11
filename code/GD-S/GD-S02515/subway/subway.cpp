#include<bits/stdc++.h>
using namespace std;
int  entrence_time[500005],the_number_of_station[500005];
bool every_station[5005][5005];
using ll=long long;int c,n,m,d,q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
struct linestation{
	int station,time_to_platform;
}line_station[5005][5005];
vector<pair<int,int>> v[5005];
int dfs(int a,int b){
	int interchange=0,mi=0x3f3f3f3f;
	vector<int> at;
	vector<int> bt;
	for(int i=1;i<=n;i++){
		if(every_station[i][a]==1&&every_station[i][b]==1)return line_station[i][a].time_to_platform +line_station[i][b].time_to_platform;
		if(every_station[i][a]==1){
			at.push_back(i);
		}
		if(every_station[i][b]==1){
			bt.push_back(i);	
		}
	}
	for(int aa=0;aa<at.size();aa++){
		for(int bb=0;bb<bt.size();bb++){
			for(int i=1;i<=the_number_of_station[at[aa]];i++){
				for(int j=1;j<=the_number_of_station[bt[bb]];j++){
					if(every_station[at[aa]][i]==1&&every_station[bt[bb]][j]==1)mi=min(mi,line_station[at[aa]][a].time_to_platform 	+line_station[bt[bb]][b].time_to_platform+line_station[at[aa]][i].time_to_platform+line_station[bt[bb]][i].time_to_platform);			
				} 
			}
		}
	}
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>entrence_time[i];
	}
	for(int i=1;i<=n;i++){
		cin>>the_number_of_station[i];
		for(int j=1;j<=the_number_of_station[i];j++){
			cin>>line_station[i][j].station>>line_station[i][j].time_to_platform  ;
			every_station[i][line_station[i][j].station]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=the_number_of_station[i];j++){
			for(int k=1;k<=the_number_of_station[i];k++){
				v[line_station[i][j].station ].push_back({line_station[i][k].station ,0});
				v[line_station[i][k].station ].push_back({line_station[i][j].station ,0});
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=the_number_of_station[i];k++){
				for(int l=1;l<=the_number_of_station[j];l++){
					if(line_station[i][k].station ==line_station[j][l].station ){
						v[line_station[i][k].station ].push_back({line_station[j][l].station ,line_station[i][k].time_to_platform +line_station[j][l].time_to_platform });
						v[line_station[j][l].station ].push_back({line_station[i][k].station ,line_station[i][k].time_to_platform +line_station[j][l].time_to_platform});
					}
				}
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans=entrence_time[a]+entrence_time[b]+dfs(a,b);
		cout<<ans<<endl;
	}
	return 0;
}


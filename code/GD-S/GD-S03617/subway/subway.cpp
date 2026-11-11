#include<bits/stdc++.h>
using namespace std;
struct line{
	long long total=0;
	vector<long long>a;//经过地铁站 
	vector<long long>t;//站厅到站台 
}k[505];//线路 
struct sta{
	int ending;
	int line_n;
	int time_exit;
};
long long x,y;//出行计划 
long long c,n,m,d,q;
long long w[505];//站口到站厅 
vector<sta>station[505];
//queue<sta>q;
long long ans;
long long BFS(int last_line,int last_sta){
	if(last_sta==y){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i].total;
		for(int j=1;j<=k[i].total;j++){
			int a1,t1;
			cin>>a1>>t1;
			k[i].a.push_back(a1);
			k[i].t.push_back(t1);
		}
		
		for(int j=1;j<=k[i].total;j++){
			for(int z=1;z<=k[i].total;z++){
				if(j==z){
					continue;
				}
//				station[k[i].a[j]].push_back({k[i].a[z],i,k[i].a[z].t});
//				station[k[i].a[z]].push_back({k[i].a[j],i,k[i].a[j].t});
			}
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

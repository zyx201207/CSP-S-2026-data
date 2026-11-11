#include<bits/stdc++.h>
#define long long int 
using namespace std;
//手动测试 
int cs0=0;
int cs(int n,int s){
	if(cs0==1){
		cout<<s<<":"<<n;
	}
	return 0;
}
//变量 
int c,n,m,d,q;
vector<int> belou0_w[500005];
vector<int> belou0_t[500005];
int teamt0[500005];
int map0[500005];
int dps(int a1,int a2,int all_time0){
	int min0=999999999;
	for(int ii=1;ii<=m;ii++){
		if(ii==a1&&map0[ii]==0){
		continue;
		} 
		for(int i=0;i<belou0_w[a1].size();i++){
			for(int j=0;j<belou0_w[ii].size();j++){
				if(belou0_w[a1][i]==belou0_w[a2][j]){
					return all_time0+belou0_t[a1][i]+belou0_t[a2][j];
				}else if(belou0_w[a1][i]==belou0_w[ii][j]||map0[ii]==0){
					map0[ii]=1;
					min0=min(dps(ii,a2,all_time0+belou0_t[a1][i]+belou0_t[ii][j]),min0);
					map0[ii]=0;
				}
			}
		}
	} 
	return min0;
} 
signed main(){
	if(cs0==0){
		ios::sync_with_stdio(0);
		cin.tie(0);
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	}
	cin>>c>>n>>m>>d>>q;
	//程序 
	for(int i=1;i<=m;i++){
		cin>>teamt0[i];
	}
	for(int i=1;i<=n;i++){
		int nc_ac;
		cin>>nc_ac;
		for(int j=1;j<=nc_ac;j++){
			int a,b;
			cin>>a>>b;
			belou0_w[a].push_back(i);
			belou0_t[a].push_back(b);
		}
	}
	for(int x=1;x<=q;x++){
		int a1,a2,ls;
		bool kg0=1;
		cin>>a1>>a2;
		ls=a1;
		int all_time0=teamt0[a1]+teamt0[a2];
		cout<<dps(a1,a2,all_time0)<<endl;
		

	}
	
	return 0;
} 

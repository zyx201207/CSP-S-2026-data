#include<bits/stdc++.h>
#define int1 long long
using namespace std;
unordered_map<int1,map<int1,int1>> vl;
int1 c,n,m,d,pb,ps=1e18,w[500009];
vector<int>v[500009];
bool p[500009];
void ms(int1 l,int1 r,int1 d){
	//cout<<(r==l);
	
	if(l==r){
		ps=min(ps,d);
		return ;
	}
	
	if(d>ps)return ;p[l]=1;
	for(int1 o:v[l]){
		if(p[o])continue;
		ms(o,r,d+vl[o][l]);
		//cout<<vl[o][l];
	}
	p[l]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>pb;
	if(c<=11&&c>=0){
		for(int i=1;i<=m;i++){
			cin>>w[i];
			//cout<<w[m]<<'\n';
		}
		for(int i=1;i<=n;i++){
			int1 k;
			cin>>k;
			int1 a,b,c,aa,bb;
			cin>>a>>aa>>b>>bb;
			v[a].push_back(b);
			v[b].push_back(a);
			vl[a][b]=vl[b][a]=aa+bb;
			//cout<<vl[a][b];
		}
		for(int i=1;i<=pb;i++){
			int1 a,b;
			cin>>a>>b;
			ps=1e18;
			ms(a,b,0);
			//cout<<a<<' '<<b<<' '<<w[a]<<' '<<w[b]<<' ';
			cout<<ps+w[a]+w[b]<<'\n';
		}
	}
	return 0;
}

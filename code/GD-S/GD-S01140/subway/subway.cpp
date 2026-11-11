#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int q1,q2;
long long nm[500005][505];
int w[500005];
vector < pair<int,pair<int,int>> > v[500005];

void dj(int be,int en){
	queue<pair<int,pair<int,int> > > qu;
	for(auto i:v[be]){
		qu.push(i);
		nm[be][i.first]=0;
	}
	while(!qu.empty()){
		int xx=qu.front().first;
		int dd=qu.front().second.first;
		int ww=qu.front().second.first;
		qu.pop();
		for(auto pp:v[dd]){
			int loi=0;
			if(xx==pp.first&&nm[pp.second.first][xx]>nm[dd][xx]+ww){
				nm[pp.second.first][xx]=nm[dd][xx]+ww;
				loi=1;
			}else if(xx!=pp.first&&nm[pp.second.first][pp.first]>nm[pp.second.first][xx]+nm[dd][xx]+ww){
				nm[pp.second.first][pp.first]=nm[pp.second.first][xx]+nm[dd][xx]+ww;
				loi=1;
			}
			if(loi==1)qu.push(pp);
		}
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
		int xi;
		cin>>xi;
		int w1[xi],w2[xi];
		for(int j=1;j<=xi;j++){
			cin>>w1[i]>>w2[i];
			if(j!=1)v[w1[i]].push_back({i,{w1[i-1],w2[i]}});
			if(j!=1)v[w1[i-1]].push_back({i,{w1[i],w2[i-1]}});
			//                            线路    点     权值 
		}
	}
	while(q--){
		memset(nm,0x3f3f3f3f,sizeof(nm));
		cin>>q1>>q2;
		dj(q1,q2);
		long long minn=1000000000000000;
		int pol;
		for(auto pl:v[q2]){
			if(minn>nm[q2][pl.first]){
				pol=pl.first;
				minn=nm[q2][pl.first];
			}
		}
		cout<<w[q1]+w[q2]+minn+nm[q2][pol];
	}
	return 0;
}

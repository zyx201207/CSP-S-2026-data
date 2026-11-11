#include<bits/stdc++.h>
using namespace std;
int edge[50005][50005]={1000000};
int ans=0;
int c,n,m,d,q;
int mymin(int a,int b){
	if(a<b)return a;
	return b;
}
void floyd(){
	for(int k=0;k<m;k++){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
					edge[i][j]=mymin(edge[i][j],edge[i][k]+edge[k][j]);		
			}
		}
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	vector<int> w;
	for(int i=0;i<m;i++){
		int wi;
		cin>>wi;
		w.push_back(wi);
	}//地铁口->站厅 
	for(int i=0;i<n;i++){
		int ki=0;//对于第i条线路，经过ki个站点 
		cin>>ki;
		vector<int> trk;//记录车轨 
		vector<int> tii;
		while(ki--){
			int ai=0;
			cin>>ai;
			trk.push_back(ai);
			int ti=0;
			cin>>ti;
			tii.push_back(ti);
		}
		for(int j=0;j<trk.size();j++){
			for(int i1=0;i1<trk.size();i1++){
					if(edge[trk[j]][trk[i1]] == 0  ||  edge[ trk[j] ][ trk[i1] ]>tii[j]) edge[ trk[j] ][ trk[i1] ]=tii[j];//代价更小则更新 
			}
		}
	}
	floyd();
	vector<int> x,y;
	for(int i=0;i<q;i++){
		int x1,y1;
		cin>>x1>>y1;
		x.push_back(x1);
		y.push_back(y1);
	}
	ans=(w[x[0]-1]+w[y[0]-1]+edge[x[0]-1][x[0]-1]);
	ans+=edge[x[0]-1][y[0]-1];
	cout<<ans;
	for(int i=1;i<q;i++){
		cout<<'\n';
		ans=(w[x[i]-1]+w[y[i]-1]+edge[x[i]-1][x[i]-1]);
		ans+=edge[x[i]-1][y[i]-1];
		cout<<ans;
	}
	return 0;
}





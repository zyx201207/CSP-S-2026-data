#include<bits/stdc++.h>
using namespace std;
int w,n,m,d,q,rt[500005];
vector<int> x[505][2];
vector<int> r[500005];
bool l[505];
int fs(int xz,int jl,int c){
	int zx=1000000005;
	for(int i=0;i<r[xz].size();i++){
		int ij;
		for(int j=0;j<x[r[xz][i]][0].size();j++){
			if(x[r[xz][i]][0][j]==xz) ij=j;
		}
		if(!l[r[xz][i]]){
			for(int j=0;j<r[c].size();j++){
				if(r[c][j]==r[xz][i]){
					int cx;
					for(int g=0;g<x[r[xz][i]][0].size();g++){
						if(x[r[xz][i]][0][g]==c) cx=g;
					}
					return jl+x[r[xz][i]][1][cx]+x[r[xz][i]][1][ij];
				}
			}
			l[r[xz][i]]=true;
			for(int j=0;j<x[r[xz][i]][0].size();j++){
				if(ij!=j) zx=min(zx,fs(x[r[xz][i]][0][j],x[r[xz][i]][1][j]+x[r[xz][i]][1][ij]+jl,c));
			}
			l[r[xz][i]]=false;
		}
	}
	return zx;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>w>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>rt[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=0,a,t;j<k;j++){
			cin>>a>>t;
			x[i][0].push_back(a);
			x[i][1].push_back(t);
			r[a].push_back(i);
		}
	}
	for(int i=0,r,c;i<q;i++){
		cin>>r>>c;
		cout<<rt[r]+rt[c]+fs(r,0,c)<<endl;
	}
	return 0;
}

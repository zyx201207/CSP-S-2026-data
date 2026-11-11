#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q,ww[500005],f[505][505];
struct xx{
	ll v,w;
};
vector<xx> g0[500505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++){
		ll ki,ai,ti;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>ai>>ti;
			g0[ai].push_back((xx){m+i,ti});
			g0[m+i].push_back((xx){ai,ti});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=LONG_LONG_MAX/2;
		}
	}
	for(int i=1;i<=m;i++){
		int siz=g0[i].size();
		//cout<<i<<"\n";
		for(int j=0;j<siz;j++){
			for(int k=0;k<j;k++){
				//cout<<g0[i][j].v<<" "<<g0[i][k].v<<" "<<f[g0[i][j].v][g0[i][k].v]<<" "<<g0[i][j].w+g0[i][k].w<<"\n";
				f[g0[i][k].v-m][g0[i][j].v-m]=f[g0[i][j].v-m][g0[i][k].v-m]=min(f[g0[i][j].v-m][g0[i][k].v-m],g0[i][j].w+g0[i][k].w);
			}
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<f[i][j]<<" ";
		cout<<"\n";
	}*/
	
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ll minn=LONG_LONG_MAX;
		for(int i=0;i<g0[xr].size();i++)
			for(int j=0;j<g0[yr].size();j++){
				minn=min(minn,f[g0[xr][i].v-m][g0[yr][j].v-m]+g0[xr][i].w+g0[yr][j].w);
			}
		cout<<minn+ww[xr]+ww[yr]<<"\n";
	}
	return 0;
} 

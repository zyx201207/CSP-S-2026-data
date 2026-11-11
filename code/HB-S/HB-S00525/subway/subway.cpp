#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,a,b,c,d,x,y,n;
ll v[500010],k[5100],w,f[510][510];
struct h{
	int n;
	ll w;
};
vector <h> hd[500010];
void floydqq(){
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			for(int k=1;k<=a;k++){
				if(f[i][j]+f[j][k]<f[i][k]){
					f[i][k]=f[i][j]+f[j][k];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C;
	cin>>a>>b>>c>>d;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=b;i++){
		f[i][i]=0;
		cin>>v[i];
	}
	for(int i=1;i<=a;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>n>>w;
			hd[n].push_back({i,w});
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=0;j<hd[i].size();j++){
			for(int k=0;k<hd[i].size();k++){
				if(j!=k){
					h u=hd[i][j],v=hd[i][k];
					if(u.w+v.w<f[u.n][v.n]) f[u.n][v.n]=f[v.n][u.n]=u.w+v.w;
				}
			}
		}
	}
	floydqq();
	for(int i=1;i<=d;i++){
		cin>>x>>y;
		ll wow=0x3f3f3f3f3f3f3f3f,owo=0;
		for(int i=0;i<hd[x].size();i++){
			for(int j=0;j<hd[y].size();j++){
				h u=hd[x][i],v=hd[y][j];
				owo=u.w+v.w+f[u.n][v.n];
				if(owo<wow) wow=owo;
			}
		}
		cout<<wow+v[x]+v[y]<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,a[500009],ra,numm,nnum,nnnn,rra=99999999;
vector<int> b[500009];
vector<int> kk[500009];
struct sss{
	int tt;
	int aa;
}s[59][500009];
void dfs(int noww,int nextt,int lastt,int xx){
	numm=b[noww].size();
	nnum=kk[noww].size();
	bool vcxz=false;
	nnnn=kk[noww].size();
	for(int i=0;i<numm;i++){
		int v=b[noww][i];
		if(v==nextt){
			int vvv=kk[v].size();
			bool cxz=false;
			for(int i=0;i<vvv;i++){
				if(kk[v][i]);
			}
			rra=min(rra,ra);
			return;
		};
		for(int j=0;j<nnnn;j++){
			int vv=kk[noww][j];
			if(vv!=xx){
				vcxz=true;
				ra+=s[vv][noww].tt+s[xx][noww].tt;
			}
			dfs(v,nextt,noww,vv);
			if(vcxz) ra-=(s[vv][noww].tt+s[xx][noww].tt);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[i][j].aa;
			cin>>s[i][j].tt;
			b[s[i][j-1].aa].push_back(s[i][j].aa);
			kk[s[i][j].aa].push_back(i);
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<kk[x].size();i++){
			ra=s[kk[x][i]][x].tt+s[kk[x][i]][y].tt;
			dfs(x,y,0,kk[x][i]);
		}
		cout<<rra+a[x]+a[y]<<endl;
	}
	return 0;
}

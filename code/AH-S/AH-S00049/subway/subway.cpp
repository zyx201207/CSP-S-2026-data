#include<bits/stdc++.h>
using namespace std;
#define int long long
int go[500010];
int ai[1010][1010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++){
		cin>>go[x];
	}
	memset(ai,0x3f,sizeof ai);
	int cnt;
	if(c>=9&&c<=11){
		cnt=m;
		for(int x=1;x<=n;x++){
			int k;
			cin>>k;
			int a,b,c,d;
			cin>>a>>b;
			if(k==2){
				cin>>c>>d;
				ai[a][c]=ai[c][a]=b+d;
			}
		}
	}
	else{
		cnt=m+n;
		for(int x=1;x<=n;x++){
			int k;
			cin>>k;
			for(int y=1;y<=k;y++){
				int a,b;
				cin>>a>>b;
				ai[a][x+m]=ai[x+m][a]=b;
			}
		}
	}
	for(int z=1;z<=cnt;z++){
		for(int x=1;x<=cnt;x++){
			for(int y=x+1;y<=cnt;y++){
				ai[x][y]=min(ai[x][y],ai[x][z]+ai[z][y]);
			}
		}
	}
	for(int x=1;x<=q;x++){
		int a,b;
		cin>>a>>b;
		cout<<ai[min(a,b)][max(a,b)]+go[a]+go[b]<<'\n';
	}
	return 0;
}

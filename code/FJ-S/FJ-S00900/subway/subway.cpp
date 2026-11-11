#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd(){
	int x=0;
	char ch=getchar();
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}return x;
}
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>>nm[500005];
int kksi,aki,ati;
int floy[505][505];
int xr,yr,ans;

int i,j,k,u,v;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(i=1;i<=m;i++){
		w[i]=rd();
	}
	for(i=1;i<=n;i++){
		kksi=rd();
		while(kksi--){
			aki=rd();ati=rd();
			nm[aki].push_back({i,ati});
		}
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		if(i==j)floy[i][j]=0;else floy[i][j]=5e11;
	}
	for(i=1;i<=m;i++){
		for(u=0;u<nm[i].size();u++){
			for(v=0;v<u;v++){
				floy[nm[i][u].first][nm[i][v].first]=min(floy[nm[i][u].first][nm[i][v].first],nm[i][u].second+nm[i][v].second);
				floy[nm[i][v].first][nm[i][u].first]=floy[nm[i][u].first][nm[i][v].first];
			}
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				floy[i][j]=min(floy[i][j],floy[i][k]+floy[k][j]);
			}
		}
	}
	while(q--){
		xr=rd();yr=rd();
		ans=LLONG_MAX;
		for(auto ur:nm[xr]){
			for(auto vr:nm[yr]){
				ans=min(ans,ur.second+floy[ur.first][vr.first]+vr.second);
			}
		}
		printf("%lld\n",ans+w[xr]+w[yr]);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int n[N],y[N];//每个地铁站的地铁口走到站厅需要的时间
int z[505][N];
int as,n1,m,d,q,k,a,b,c,qi,zhong,ans,cnt;
int aaa(int x1,int y1){
	if(x1==qi){
		cnt+=n[x1]+n[y1];
		y[x1]=1;
	}else if(y[x1]==1){
		return 0;
	}
	if(x1==y1){
		cout << cnt;
		return 0;
	}
	for(int i=1;i<=n1;i++){
		if(z[i][x1]){
			for(int j=1;j<=m;j++){
				if(z[i][j]||j!=x1){
					y[x1]=1;
					cnt+=z[i][j];
					aaa(j,y1);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> as >> n1 >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> n[i];
	}
	c=1;
	for(int i=n1;i>0;i--){
		cin >> k;
		for(int i=1;i<=k;i++){
			cin >> a >> b;
			z[c][a]=b;
		}
		c++;
	}
	while(q--){
		cin >> qi >> zhong;
		aaa(qi,zhong);
	}
}
//Oct31==Dec25? 

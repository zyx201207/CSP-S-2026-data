#include<bits/stdc++.h>
#define intt long long
using namespace std;
const intt inf=LONG_LONG_MAX; 
intt c,n,m,d,p;
intt w[500505],dd[2005][2005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(intt i=1;i<=m;i++){
		cin>>w[i];
	}
	for(intt i=1;i<=m+n;i++){
		for(intt j=1;j<=m+n;j++){
			dd[i][j]=inf;
		}
		dd[i][i]=0;
	}
	
	for(intt i=1;i<=n;i++){
		intt k;
		cin>>k;
		for(intt j=1;j<=k;j++){
			intt x,y;
			cin>>x>>y;
			dd[m+i][x]=y;
			dd[x][m+i]=y;
		}
	}
	for(intt k=1;k<=n+m;k++){
		for(intt i=1;i<=n+m;i++){
			for(intt j=1;j<=n+m;j++){
				if(dd[i][k]==inf) break;
				if(dd[k][j]==inf) continue;
				dd[i][j]=min(dd[i][j],dd[j][i]);
				if(dd[i][k]+dd[k][j]<dd[i][j]){
					dd[i][j]=dd[i][k]+dd[k][j];
					dd[j][i]=dd[i][k]+dd[k][j];
				}
//				cout<<i<<"->"<<j<<' '<<dd[i][j]<<'\n';
			}
		}
	}
	while(p--){
		intt x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dd[x][y]<<'\n';
	}
	return 0;
} 

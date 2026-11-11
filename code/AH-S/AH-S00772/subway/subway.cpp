#include<bits/stdc++.h>
using namespace std;
struct sta{
	int a[25],t[25];
}line[505];
int c,n,m,d,q,w[500005],len[500005];
struct ac{
	int to,w;
};
vector<ac> e[500005];
long long f[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(m<=400){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=1e9;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>line[i].a[j]>>line[i].t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				e[line[i].a[j]].push_back({line[i].a[l],line[i].t[j]+line[i].t[l]});
				if(m<=400){
					f[line[i].a[j]][line[i].a[l]]=min(f[line[i].a[j]][line[i].a[l]],(long long)(line[i].t[j]+line[i].t[l]));
				}
			}
		}
	}
	if(m<=400){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		while(q--){
			int st,ed;
			cin>>st>>ed;
			cout<<w[st]+w[ed]+f[st][ed]<<"\n";
		}
	}
	else{
		
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
vector<long long> t[510],line[510];
long long w[500010];
long long f[1010][1010],use[1010][1010][3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long  v,tt;
			cin>>v>>tt;
			line[i].push_back(v);
			t[i].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n && i!=j;j++){
			f[i][j]=1000000000;
		}
	}
	for(int k=1;k<=n;k++){
		int l=line[k].size();
		for(int i=0;i<l;i++){
			for(int j=i+1;j<l;j++){
				if(f[i][j]<t[k][i]+t[k][j]){
					use[i][j][1]=t[k][i];
					use[i][j][2]=t[k][j];
					f[i][j]<t[k][i]+t[k][j];
				}
				f[j][i]=f[i][j];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || i==k || j==k){
					continue;
				}
				long long use1=0;
				use1=use[i][k][2]+use[k][j][1];
				if(f[i][j]<f[i][k]+f[k][j]+use1){
					f[i][j]=f[i][k]+f[k][j]+use1;
					use[i][j][1]=use[i][k][1];
					use[i][j][2]=use[k][j][2];
					use[j][i][2]=use[i][k][1];
					use[j][i][1]=use[k][j][2];
				}
				f[j][i]=f[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]<<endl;
	}
	return 0;
}

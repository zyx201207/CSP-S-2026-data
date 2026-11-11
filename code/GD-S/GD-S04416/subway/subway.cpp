#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
long long w[N];
long long a[N][N];
long long t[N][N];
long long k_n[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		k_n[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(c>=12&&c<=19){
		while(p--){
			int x,y,cnt=0,f=0;
			cin>>x>>y;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k_n[i];j++){
					for(int v=1;v<=k_n[i];v++){
						if(a[i][j]==x&&a[i][v]==y){
							cnt = 2*t[i][j]+w[x]+w[y];
							f=1;
							break;
						}
					}
				}
			}
			if(f==0){
			cnt =  4*t[1][1]+w[x]+w[y];
			}
		cout<<cnt<<endl;
		}
	}
	if(c>=20&&c<=21){
		while(p--){
			int x,y,cnt=0;
			cin>>x>>y;
			for(int i=1;i<=2;i++){
				for(int j=1;j<=k_n[i];j++){
					for(int v=1;v<=k_n[i];v++){
						if(a[i][j]==x&&a[i][v]==y){
							cnt = t[i][j]+t[i][v]+w[x]+w[y];
						}
						else{
							if(a[1][j]==a[2][v]){
								cnt =  t[1][j]+t[2][v]+t[j][x]+t[v][y]+w[x]+w[y];
							}
						}
					}
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
} 

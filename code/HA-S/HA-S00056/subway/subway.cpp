#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,p,s1,s2;
struct u{
	int xb,num;
}a[509][509];
int zt[509];
int fl[29][509],flyd[509][509];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			fl[i][j]=1e17;
			a[i][j].num=1e17;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>zt[i];
	}
	for(int i=1;i<=m;i++){
		int o,to,ti;
		cin>>o;
		for(int j=1;j<=o;j++){
			cin>>to>>ti;
			fl[i][to]=ti;
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(fl[l][j]!=1e9&&fl[i][j]!=1e9){
					if(a[l][i].num>min(fl[l][j],fl[i][j])){
						a[l][i].num=min(fl[l][j],fl[i][j]);
						a[l][i].xb=j;
					}
				}
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j].num>a[i][l].num+a[l][j].num+fl[j][j]+fl[l][j]){
					a[i][j].num=a[i][l].num+a[l][j].num+fl[j][j]+fl[l][j];
					a[i][j].xb=l;
				}
			}
		}
	}
	for(int u=1;u<=p;u++){
		int minn=1e9;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(fl[i][s1]!=1e9&&fl[j][s2]!=1e9){
					if(i==j){
						minn=min(minn,zt[s1]+fl[i][s1]+fl[j][s2]+zt[s2]);
					}else{
//						cout<<zt[s1]<<" "<<fl[i][s1]<<" "<<fl[i][a[i][j].xb]<<" "<<a[i][j].num<<" "<<fl[j][s2]<<" "<<zt[s2]<<endl;
						minn=min(minn,zt[s1]+fl[i][s1]+fl[i][a[i][j].xb]+a[i][j].num+fl[j][s2]+zt[s2]);
					}
				}
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

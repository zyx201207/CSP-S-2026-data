#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,a,w[500005],k[501][10001],k1[501][10000],x[2000],y[2000];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=1;j<=a;j++){
			cin>>k[i][j]>>k1[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		long long t1=0,t2=0,xl1[20],xl[20],mixx=1e+8,xt[21]={0};
		cin>>x[i]>>y[i];
		for(int h=1;h<=n;h++){
			for(int j=1;j<=n;j++){
				if(k[h][j]==0){
					break;
				}
				if(i==j){
					j++;
				}
				if(k[h][j]==x[i]){
					xl[t1]=h;
					t1++;
				}
				if(k[h][j]==y[i]){
					xl1[t2]=h;
					t2++;
				}
			}
		}
		cout<<(x[i]+y[i])*w[i]<<endl;
	}
	return 0;
}

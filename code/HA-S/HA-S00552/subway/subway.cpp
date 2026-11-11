#include<iostream>
#include<cstdio>
using namespace std;
long long c,n,m,d,q,w[500010],dis[1010][1010],bh[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=(m+1)*d;i++){
		for(int j=1;j<=(m+1)*d;j++){
			dis[i][j]=4e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int pre;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			bh[a]++;
			dis[a*d][a*d+bh[a]]=t;
			dis[a*d+bh[a]][a*d]=t;
//			cout<<"test"<<a*d<<' '<<a*d+bh[a]<<' '<<t<<endl;
			if(j>=2){
				dis[a*d+bh[a]][pre*d+bh[pre]]=0;
				dis[pre*d+bh[pre]][a*d+bh[a]]=0;
//				cout<<"test"<<a*d+bh[a]<<' '<<pre*d+bh[pre]<<' '<<0<<endl;
			}
			pre=a;
		}
	}
	for(int k=1;k<=m*d+bh[m];k++){
		for(int i=1;i<=m*d+bh[m];i++){
			for(int j=1;j<=m*d+bh[m];j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x*d][y*d]+w[y]<<endl;
	}
	return 0;
}
//12

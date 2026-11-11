#include<bits/stdc++.h>
using namespace std;
struct shi{
	int xi;int ti;
};
int kt[500005];shi tt[500005][25];long long zhuan[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kt[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ai,t;
			cin>>ai>>t;
			tt[ai][++tt[ai][0].xi].ti=t;
			tt[ai][tt[ai][0].xi].xi=i;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=tt[i][0].xi;j++){
//			cout<<tt[i][j].xi<<' ';
//		}
//		cout<<endl;
//	}
	memset(zhuan,0x3f,sizeof zhuan);
	for(int i=1;i<=m;i++){
		zhuan[i][i]=0;
		for(int j=1;j<=tt[i][0].xi;j++){
			for(int k=j+1;k<=tt[i][0].xi;k++){
				zhuan[tt[i][j].xi][tt[i][k].xi]=min(zhuan[tt[i][j].xi][tt[i][k].xi],(long long)tt[i][j].ti+tt[i][k].ti);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<zhuan[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				zhuan[i][j]=min(zhuan[i][j],zhuan[i][k]+zhuan[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<zhuan[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		if(l>r){
			int lr=l;
			l=r;
			r=lr;
		}
		long long ans=1e16;
		for(int j=1;j<=tt[l][0].xi;j++){
			for(int k=1;k<=tt[r][0].xi;k++){
				ans=min(ans,zhuan[tt[l][j].xi][tt[r][k].xi]+tt[l][j].ti+tt[r][k].ti);
			}
		}
		ans+=kt[l]+kt[r];
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 4 9 2 10
1 2 3 4 5 6 7 8 9
4 1 1 2 2 3 3 4 4
4 3 3 6 6 7 7 5 5
3 6 6 8 8 9 9
2 2 2 8 8
*/

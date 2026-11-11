#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,g1,g2,g3,g4,sum=0,g5,g6,g7,g8;
	cin>>c>>n>>m>>d>>q;
	int k[n+5],a[n+2][m+2],t[n+2][m+2],r1[q+5],r2[q+5],tw[m+5];
	for(int i=1;i<=m;i++){
		cin>>tw[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r1[i]>>r2[i];
	}
	for(int i=1;i<=n;i++){
		for(int z=1;z<=n;z++){
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[i];l++){
					if(a[i][j]==a[z][l]) g1=i,g2=z,g3=j,g4=l;
				}
			}
		}
	}
	for(int z=1;z<=q;z++){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]=r2[z]) g5=i,g6=j;
			if(a[i][j]=r1[z]) g7=i,g8=j;
		}
	}
}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k[j];l++){
				sum=tw[r1[i]]+t[g7][g8]+t[g1][g3]+t[g3][g4]+t[g5][g6]+tw[r2[i]];
			}
		}
	}
			
			
			cout<<sum;
	return 0;
} 


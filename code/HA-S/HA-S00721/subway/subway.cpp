#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,c[50005][600],dd[50005][600],z[100000],x,v[100000],n,m,d,q,w[100000],l[100000],tt,tt1,ooo,tt2,tt3;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int www[100000];
	int u;
	cin>>u>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>z[i];
		for(int j=1;j<=z[i];j++){
			cin>>c[i][j];
			cin>>dd[i][j];
		}
	}
	for(long long po=1;po<=d;po++){
		tt=0;
		tt1=0;
		tt2=0;
		cin>>v[po]>>l[po];
		tt=tt+w[v[po]]+w[l[po]];
		bool oo=0,kk=0;
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=z[i];j++){
				if(c[i][j]==v[po]){
					oo=1;
					ooo=i;
				}	
				if(oo==1){
					tt1=tt1+dd[i][j];
					www[j]=c[i][j];
				}
				if(c[i][j]==l[po]&&oo==1){
					tt=tt+tt1;
					kk=1;
					break;
				}
			}
			oo=0;
			if(kk==1){
				break;
			}else{
				tt1=0;
			}
		}
		if(tt!=w[v[po]]+w[l[po]]){
			cout<<tt<<"\n";
		}else{
			bool ooooo=0;
			for(long long i=1;i<=n;i++){
				if(i==ooo){
					break;
				}
				for(long long j=1;j<=z[i];j++){
					if(c[i][j]==www[j]){
						ooooo=1;
					}
					if(ooooo==1){
						tt2+=dd[i][j];
					}
					if(c[i][j]==l[po]&&ooooo==1){
						kk=1;
						for(long long jj=j+1;jj<=z[i];jj++){
							tt1=tt1-dd[i][jj];
						}
					}
					
				}
			}
			cout<<tt+tt1+tt2<<"\n";
		}
	}
	
}

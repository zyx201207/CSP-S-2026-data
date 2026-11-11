#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5E5+505;
long long c,n,m,b,q,w[M],ds[N][N],ds2[N][N];
int pl[M][23],pld[M];
struct li{
	int p1;
	int p2;
	long long d;
}mp[M];
struct atb{
	int a;
	int b;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ds,0x3f,sizeof(ds));
	memset(ds2,0x3f,sizeof(ds2));
	cin>>c>>n>>m>>b>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cp1=0;
	long long k;
	for(int i=1;i<=n;i++){
		//cout<<1;
		cin>>k;
		for(int j=1;j<=k;j++){
			//cout<<2<<k<<' ';
			int a;
			long long t;
			
			cin>>a>>t;
			//cout<<k;
			li l;
			l.p1=m+i;
			l.p2=a;
			l.d=t;
			
			mp[cp1]=l;
			pl[a][pld[a]]=cp1;
			pld[a]++;
			cp1++;
			//cout<<'a'<<j<<' '<<k<<' ';
		}
	}
	//cout<<cp1;
	//for(int i=0;i<cp1;i++)cout<<mp[i].p1<<' '<<mp[i].p2<<' '<<mp[i].d<<' '<<'\n';
	for(int i=1;i<=n;i++){
		ds[i][i]=0;
		ds2[i][i]=0;
	}
	for(int i=0;i<cp1;i++){
		int l1=mp[i].p1-m;
		int P=mp[i].p2;
		long long d1=mp[i].d;
		for(int j=0;j<pld[P];j++){
			//cout<<1;
			ds[l1][mp[pl[P][j]].p1-m]=min(ds[l1][mp[pl[P][j]].p1-m],d1+mp[pl[P][j]].d);
			
		}
	}
	//for(int i=1;i<=n;i++)ds[i][i]=0;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ds[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	ds[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			int xx=0,yy=0;
			for(int k=1;k<=n;k++){
				if(ds2[i][k]==ds2[0][0])continue;
				for(int l=1;l<=n;l++){
					if(ds2[i][l]!=ds2[0][0])continue;
					if(ds2[i][xx]+ds[xx][yy]>ds2[i][k]+ds[k][l]){
						xx=k,yy=l;
					}
				}
			}
			ds2[i][yy]=ds2[i][xx]+ds[xx][yy];
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ds2[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	long long ans=ds2[0][0];
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=ds2[0][0];
		for(int j=0;j<pld[x];j++){
			for(int k=0;k<pld[y];k++){
				ans=min(ans,mp[pl[x][j]].d+mp[pl[y][k]].d+ds2[mp[pl[x][j]].p1-m][mp[pl[y][k]].p1-m]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

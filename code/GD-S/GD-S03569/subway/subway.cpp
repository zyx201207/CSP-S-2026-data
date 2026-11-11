#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[505][505],t[505][50005],ans;
int s[50005][505];
int k,n,m,d,q,w[500005];//n是地铁线数(500)，m是地铁站数(5x10^5),q是计划数,最多经过d条,w[i]是地铁口到站厅 
//a[i]是线上的地铁，t[i]是站台到站厅 
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;
//	cout<<n<<"++++++++++++++\n";
	cin>>n>>m>>d>>q;
//	cout<<n<<' '<<m<<' '<<d<<' '<<q<<"============\n";
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	for(int i=1;i<=m;i++){
//		cout<<w[i]<<' ';
//	}
//	cout<<'\n';
	int x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			t[i][x]=read();
			s[x][++s[x][0]]=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<'\n';
//		for(int j=1;j<=m;j++){
//			cout<<t[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=LONG_LONG_MAX;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
//		cout<<i<<'\n';
		for(int j=1;j<=s[i][0];j++){
//			cout<<s[i][j]<<' ';
			for(int kk=j+1;kk<=s[i][0];kk++){
				ll flag=f[s[i][j]][s[i][kk]];
				f[s[i][j]][s[i][kk]]=f[s[i][kk]][s[i][j]]=min(f[s[i][j]][s[i][kk]],t[s[i][j]][i]+t[s[i][kk]][i]);
			}
		}
//		cout<<'\n';
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
//		}
//	}
//	cout<<"+++++++++++++++++++++++++++\n";
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][kk]==LONG_LONG_MAX||f[kk][j]==LONG_LONG_MAX) continue;
				if(f[i][j]>f[i][kk]+f[kk][j]){
					f[i][j]=f[i][kk]+f[kk][j];
//					cout<<kk<<' '<<i<<' '<<j<<'\n';
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
//		}
//	}
	while(q--){
		cin>>x>>y;
		int xx,yy;
		ans=LONG_LONG_MAX;
		for(int i=1;i<=s[x][0];i++){
			for(int j=1;j<=s[y][0];j++){
				xx=s[x][i];yy=s[y][j];
				ans=min(ans,w[x]+w[y]+t[xx][x]+t[yy][y]+f[xx][yy]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
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
*/
}

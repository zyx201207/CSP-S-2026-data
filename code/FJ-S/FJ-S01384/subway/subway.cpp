#include<iostream>
#include<cstring>
using namespace std;
const int N=505,M=5e5+5,D=25;
long long w[M],t[D][M],num[M],stop[M][D],dist[D][D];
inline int read(){
	int x=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')x=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read();
			stop[x][++num[x]]=i;
			t[i][x]=read();
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			for(int h=1;h<=num[i];h++){
				int x=stop[i][j],y=stop[i][h];
				dist[x][y]=min(dist[x][y],t[x][i]+t[y][i]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int a=read(),b=read();
		long long ans=0;
		for(int i=1;i<=num[a];i++){
			for(int j=1;j<=num[b];j++){
				int x=stop[a][i],y=stop[b][j];
				if(!ans||t[x][a]+t[y][b]+dist[x][y]<ans)ans=t[x][a]+t[y][b]+dist[x][y];
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}


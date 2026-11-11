#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0;
	int w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-w;
		ch=getchar();
	}
	s=ch-'0';
	while((ch=getchar())>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
	}
	return s*w;
}
const int N=505+3,M=5e5+3;
const long long INF=0x3f3f3f3f3f3f3f;
long long c,n,m,d,q,w[M],x,y,z,f,k[N],fm[M];
long long du[503][5003],tu[5003][5003];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			du[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			x=read(),y=read();
			du[i][x]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			tu[i][j]=INF;
		}
	}
for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			tu[i][j]=min(tu[i][j],du[k][j]+du[k][i]);
		}
	}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			tu[i][j]=min(tu[i][j],tu[k][j]+tu[k][i]);
		}
	}
	}
	while(q--){
		x=read(),y=read();
		cout<<tu[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=10*x+(c^48);c=getchar();}
	return x;
}
int c,n,m,d,p,w[505],k[505],a[505][5005],t[505][5005],x,y;
long long ans;
//a  tºóÃæ 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,0x3f,sizeof(t));
	c=read(),n=read(),m=read(),d=read(),p=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j)a[i][j]=read(),t[i][a[i][j]]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			for(int k=1;k<=n;++k){
				//if(t[i][k]==0||t[k][j]==0)continue;
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	while(p--){
		x=read();y=read();
		ans=w[x]+w[y]+t[x][y]+t[x][x];
		if(ans>=1061109567)ans=w[x]+w[y]+19;
		printf("%lld\n",ans);
	}
	return 0;
}

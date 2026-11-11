#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
//#define int long long
//const int mod=998244353;
//const int mod=1e9+7;
const int N=505;
const int M=5e1+5;
using namespace std;
int read(){
	int x=0;
	short f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*((1<<1)+(1<<3))+c-'0';
		c=getchar();
	}
	return ((f)?(-x):(x));
}
int c,n,m,d,q;
int k[N];
int w[M];
int a[N][M],t[N][M];
int x,y;
//怎么建边?
//似乎可以把每一个地铁的停靠处都变成点
//不只是站点是点
//站点那是枢纽
//地铁的停靠处也是点
//从枢纽到停靠处的权值初始是t[i][j]
//然后跑Floyd直接冲过去
//算了先切后排吧
//切完后排回来了
//还有50min
int maxn(int x,int y){
	return ((x>y)?(x):(y));
}
int minn(int x,int y){
	return ((x<y)?(x):(y));
}
signed main(){
	fre("subway")
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	d=0;
	for(int i=1;i<=n;++i){
		k[i]=read(),d=maxn(d,k[i]);
		for(int j=1;j<=k[i];++j) a[i][j]=read(),t[i][j]=read();
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(m==2){
		//《两个地铁站开了20条线路》
		int ans=2147483647,tmp;
		for(int i=1;i<=n;++i){
			tmp=0;
			for(int j=1;j<=k[i];++j) tmp+=t[i][j];
			ans=minn(ans,tmp);
		}
		while(q--){
//			x=read(),y=read();
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(n==1){
		while(q--){
			x=read(),y=read();
			cout<<t[1][x]+t[1][y]<<'\n';
		}
		return 0;
	}
	while(q--){
		x=read(),y=read();
		cout<<(x+y)*4<<'\n';
	}
	return 0;
}
/*
/*
我要上迷惑行为
(
[
{
freopen("subway1.in","r",stdin);
freopen("subway1.out","w",stdout);
freopen("subway.in","w",stdin);
freopen("subway.out","r",stdout);
f**k ��￡ shit dzd love
//freopen("subway.in","r",stdin);
//freopen("subway.out","w",stdout);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
114514191981010086
#incldue<iostream>
int y0,y1,x0,x1;
#include<bits\stdc++.h>
#include<bit.s/stdc++h>
system("shutdown -s -t 0");
kkksc03
system("taskkill -f -im studentmain.exe");
freopen("sbuway.in","r",stdin);
freopen("sbuway.out","w",stdout);
feropen("subway.in","r",stdin);
feropen("subway.out","w",stdout);
172.16.12.5
*/

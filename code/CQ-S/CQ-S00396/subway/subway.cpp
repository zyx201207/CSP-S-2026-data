#include<bits/stdc++.h>
using namespace std;
/*
得到了一个O((m+q)d^2+n^3)的做法……
3.7e8 能过吗这。 
配重 aa 
*/
int c,n,m,d,q,w[500001];
long long sp[501][501];
struct fk{int org,dis;};
vector<fk>e[500001];
char buf[1<<17],*S=buf,*T=buf;
char gc(){
	if(S==T){
		T=(S=buf)+fread(buf,1,1<<17,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
int rd(){
	int a=0;char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)){
		a=(a<<1)+(a<<3)+(ch^48);
		ch=gc();
	}
	return a;
}
template<typename T>void read(T&x){x=rd();}
template<typename T,typename... _R>void read(T&x,_R&..._r){
	read(x);
	read(_r...);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//freopen
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	memset(sp,0x3f,sizeof sp);
	for(int i=1;i<=m;i++)w[i]=rd();
	for(int i=1;i<=n;i++){
		int k=rd();
		while(k--){
			int t,a;read(a,t);
			for(fk hh:e[a]){
				int os=hh.org;
				int ts=hh.dis;
				sp[i][os]=min(sp[i][os],0ll+ts+t);
				sp[os][i]=min(sp[os][i],0ll+ts+t);
			}
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)sp[i][i]=0;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)if(i!=j&&j!=k&&i!=k)sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
	while(q--){
		long long ans=LLONG_MAX;
		int fr=rd(),to=rd();
		for(fk it1:e[fr])
		for(fk it2:e[to])
		ans=min(ans,0ll+w[fr]+w[to]+sp[it1.org][it2.org]+it1.dis+it2.dis);
		cout<<ans<<'\n';
	}
	return 0;
}

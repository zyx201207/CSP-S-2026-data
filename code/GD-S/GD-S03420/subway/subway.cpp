#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+5;
int n,m,d,q;
int w[N];
ll dis[505][505];
struct edge{ int to,t; };
vector<edge> mp[N];
namespace Fast_IO{
	char bufin[1<<20],*fs,*ft;
	char getc(){
		return (fs==ft&&(ft=(fs=bufin)+fread(bufin,1,1<<20,stdin))==fs)?EOF:*fs++;
	}
	void read(int &x){
		x=0;
		char ch;
		do ch=getc();
		while(!isdigit(ch));
		do x=x*10+ch-'0',ch=getc();
		while(isdigit(ch));
	}
	char bufout[(1<<20)+100];
	int tp=-1;
	void flush(){
		fwrite(bufout,1,tp+1,stdout);
		tp=-1;
	}
	void putc(char ch){
		bufout[++tp]=ch;
		if(tp&(1<<20)) flush();
	}
	void write(ll x){
		int num[20],tot=0;
		do num[++tot]=x%10,x/=10;
		while(x);
		while(tot) bufout[++tp]=num[tot--]+'0';
		if(tp&(1<<20)) flush();
	}
}
using Fast_IO::read;
using Fast_IO::putc;
using Fast_IO::write;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _c;
	read(_c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		int k;
		read(k);
		for(int j=1;j<=k;j++){
			int a,t;
			read(a),read(t);
			mp[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=2e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=mp[i].size();
		for(int j=0;j<sz;j++){
			for(int k=j+1;k<sz;k++){
				dis[mp[i][j].to][mp[i][k].to]=min(dis[mp[i][j].to][mp[i][k].to],(ll)mp[i][j].t+mp[i][k].t);
				dis[mp[i][k].to][mp[i][j].to]=dis[mp[i][j].to][mp[i][k].to];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		read(x),read(y);
		ll ans=2e18;
		for(auto u:mp[x])
			for(auto v:mp[y])
				ans=min(ans,u.t+v.t+dis[u.to][v.to]);
		ans+=w[x]+w[y];
		write(ans),putc('\n');
	}
	Fast_IO::flush();
}

#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read(){
	int x=0,s=1,ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')s=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return s*x;
}
const int N=500005,M=505;
int c,n,m,d,q,w[N],t[M][M];
vector<pair<int,int> > a[N];
inline void chkmin(int &x,int y){x=x<y?x:y;}
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	memset(t,0x3f,sizeof t);
	c=rd,n=rd,m=rd,d=rd,q=rd;
	for(int i=1;i<=m;++i)w[i]=rd;
	for(int i=1,k;i<=n;++i){
		k=rd,t[i][i]=0;
		for(int j=0,st,tm;j<k;++j)st=rd,tm=rd,a[st].push_back({i,tm});
	}
	for(int i=1;i<=m;++i)
		for(auto [A,B]:a[i])for(auto [C,D]:a[i])
			t[A][C]=t[C][A]=min(t[A][C],B+D);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)chkmin(t[i][j],t[i][k]+t[k][j]);
	for(int i=1,x,y,res;i<=q;++i){
		x=rd,y=rd,res=1e18;
		for(auto [A,B]:a[x])for(auto [C,D]:a[y])chkmin(res,t[A][C]+B+D);
		res+=w[x]+w[y],cout<<res<<'\n';
	}
	return 0;
}

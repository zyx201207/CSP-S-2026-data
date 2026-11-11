#include<bits/stdc++.h>
using namespace std;
#define getc() (ss==tt&&(tt=(ss=In)+fread(In,1,1<<15,stdin)),ss==tt?EOF:*ss++)
char In[1<<15],*ss=In,*tt=In;
template<class T>
void read(T&x){
	char c=getc();bool f=1;x=0;
	for(;!isdigit(c);f^=(c=='-'),c=getc());
	for(;isdigit(c);x=(x<<3)+(x<<1)-(c^48),c=getc());
	x=f?-x:x;
}
typedef long long ll;
int c,n,m,d,q;
ll w[500005],f[505][505];
vector<pair<int,ll>>v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1,k;i<=n;i++){
		read(k);
		for(int j=1,x,y;j<=k;j++){
			read(x),read(y);
			v[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		for(auto j:v[i]){
			for(auto k:v[i]){
				int a=j.first,b=k.first;
				ll c=j.second,d=k.second,s=c+d;
				if(a!=b) f[a][b]=min(s,f[a][b]),f[b][a]=min(f[b][a],s);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);	
			}
		}
	}
	while(q--){
		int x,y;
		ll ans=LLONG_MAX;
		read(x),read(y);
		for(auto i:v[x]){
			for(auto j:v[y]){
				ans=min(ans,f[i.first][j.first]+w[x]+w[y]+i.second+j.second);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

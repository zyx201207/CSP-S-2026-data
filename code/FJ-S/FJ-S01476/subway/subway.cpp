#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=500005;
void in(ll &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
void int_in(int &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
ll inf;
int c,n,m,d,q;
vector<pair<int,ll> >p[N];
ll f[507][507];
ll w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	inf=f[0][0];
	int_in(c);int_in(n);int_in(m);int_in(d);int_in(q);
	for(int i=1;i<=m;i++) {
		in(w[i]);
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int k,a;
		ll t;
		int_in(k);
		for(int j=1;j<=k;j++){
			int_in(a);in(t);
			p[a].push_back({i,t});
		}
	}
	for(int a=1;a<=m;a++){
		int sz=p[a].size();
		for(int i=0;i<sz;i++){
			for(int j=i+1;j<sz;j++){
				pair<int,ll> l,r;
				l=p[a][i];
				r=p[a][j];
				f[l.first][r.first]=f[r.first][l.first]=min(l.second+r.second,f[l.first][r.first]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		int_in(x);int_in(y);
		 ll ans=inf;
		for(int i=0;i<p[x].size();i++){
			for(int j=0;j<p[y].size();j++){
				ans=min(ans,f[p[x][i].first][p[y][j].first]+p[x][i].second+p[y][j].second);
			}
		}
		
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}


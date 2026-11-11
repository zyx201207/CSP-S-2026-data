#include<bits/stdc++.h>
#define ll long long
#define il inline
#define pb push_back
using namespace std;
const int N=500000;
int c,n,m,d,q,k,a,t;
int w[N+5];
#define gc getchar
#define pc putchar
int res;char ch;
il int rd(){
	res=0,ch=gc();
	while(ch<'0'||ch>'9') ch=gc();
	while(ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return res;
}
void pt(ll x){
	if(!x) return;
	pt(x/10);
	pc(x%10+'0');
}
const int M=500;
const ll inf=1e18;
ll ans,f[M+5][M+5];
int cn,t1[N+5],t2[N+5],x,y;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
vector<pii>v[N+5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++){
		k=rd();
		while(k--){
			a=rd(),t=rd();
			v[a].pb(mp(i,t));
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=f[j][i]=inf;
	for(int i=1;i<=m;i++){
		cn=v[i].size();
		for(int j=0;j<cn;j++) t1[j]=v[i][j].fi,t2[j]=v[i][j].se;
		for(int j=0;j<cn;j++)
			for(int k=j+1;k<cn;k++)
				f[t1[j]][t1[k]]=min(f[t1[j]][t1[k]],(ll)t2[j]+t2[k]);
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		x=rd(),y=rd(),ans=inf;
		for(pii i:v[x])
			for(pii j:v[y])
				ans=min(ans,f[i.fi][j.fi]+i.se+j.se);
		pt(ans+w[x]+w[y]),pc('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read();
void write(ll x);
int c,n,m,d,q;
int const D=5e5+50;
int w[D];
int tt[D][550];
vector<int>s[550];
vector<int>uu[D];
ll ans;
bool vi[D];
void dfs(int x,int y,int fa,ll sum){
	if(x==y){
		ans=min(ans,sum);
		return;
	}
	vi[x]=true;
	for(int i=0;i<uu[x].size();i++){
		int hj=uu[x][i];
		if(hj==fa)continue;
		for(int j=0;j<s[hj].size();j++){
			int to=s[hj][j];
			if(vi[to])continue;
			if(to!=fa){
				if(to==y){
					dfs(y,y,hj,sum+tt[x][hj]+tt[to][hj]);
				}
				else{
					dfs(to,y,hj,sum+tt[x][hj]+tt[to][hj]);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k1;
		k1=read();
		for(int j=1;j<=k1;j++){
			int a1,t1;
			a1=read(),t1=read();
			uu[a1].push_back(i);
			s[i].push_back(a1);
			tt[a1][i]=t1;
		}
	}
	while(q--){
		int x1,y1;
		x1=read(),y1=read();
		ans=LONG_LONG_MAX;
		for(int i=1;i<=m;i++)vi[i]=false;
		dfs(x1,y1,0,0);
		ans+=w[x1]+w[y1];
		write(ans);
		putchar('\n');
	}
	return 0;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

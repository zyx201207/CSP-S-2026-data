#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,w[N];
int dis[N][501];
ll s[501][501];
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(s,0x3f,sizeof s);
	memset(dis,0x3f,sizeof dis);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		s[i][i]=0;
		for(int j=1,x,y;j<=k;j++){
			x=read(),y=read();
			dis[x][i]=y;
			for(int z=1;z<i;z++) if(dis[x][z]!=inf) {
				s[z][i]=s[i][z]=min(s[z][i],(ll)dis[x][z]+(ll)y); 
			}
		}
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) {
				if(s[i][k]+s[k][j]<s[i][j]) s[j][i]=s[i][j]=s[i][k]+s[k][j];
			}
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		x=read(),y=read();
		vector<int> a,b;
		ll ans=2e18;
		for(int j=1;j<=n;j++){
			if(dis[x][j]!=inf) a.push_back(j);
			if(dis[y][j]!=inf) b.push_back(j);
		} 
		for(int xx:a){
			for(int yy:b) 
				ans=min((ll)dis[x][xx]+(ll)dis[y][yy]+s[xx][yy],ans);
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
//	fclose(stdin);
//	fclose(stdout);
}

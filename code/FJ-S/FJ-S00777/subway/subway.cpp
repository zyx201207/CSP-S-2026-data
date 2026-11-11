#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c,m,d,T; 
vector<int>ve1[400010],ve2[400010];
int p[8100000],q[8100000],f[8100000],o[8100000],e[20010],len,i,j,k,X,Y,x,y,dis[20010][20],cnt[20010],num[20010][20],tot,ans;
void make_line(int x,int y,int z){
	ve1[x].push_back(y);
	ve1[y].push_back(x);
	ve2[x].push_back(z);
	ve2[y].push_back(z);
}
void det(){
	q[1]=q[len];
	p[1]=p[len];
	len--;
	int x=1;
	while(x*2<=len){
		int sx;
		if(x*2+1<=len&&q[x*2]>q[x*2+1]) sx=x*2+1;
		else sx=x*2;
		if(q[x]<=q[sx]) break;
		swap(p[x],p[sx]);
		swap(q[x],q[sx]);
		x=sx;
	}
}

void add(int xk,int y){
	q[++len]=y;
	p[len]=xk;
	int x=len;
	while(x>1){
		int sx=x/2;
		if(q[x]>=q[sx]) break;
		swap(p[x],p[sx]);
		swap(q[x],q[sx]);
		x=sx;
	}
}
void Dijstra(int x){
	memset(f,127,sizeof(f));
	memset(o,0,sizeof(o));
	f[x]=0;
	p[++len]=x;
	q[len]=0;
	while(len!=0){
		int fx=p[1];
		int fy=q[1];
		det();
		if(o[fx]) continue;
		o[fx]=1;
		for(int i=0;i<ve1[fx].size();i++){
			int sx=ve1[fx][i];
			int sy=ve2[fx][i];
			if(o[sx]==0&&fy+sy<f[sx]){
				add(sx,fy+sy);
				f[sx]=fy+sy;
			}
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>T;
	for(i=1;i<=n;i++) cin>>e[i];
	for(i=1;i<=m;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			dis[x][++cnt[x]]=y;
			num[x][cnt[x]]=++tot;
			if(j!=1)make_line(tot-1,tot,0);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=cnt[i];j++){
			for(k=1+j;k<=cnt[i];k++){
				make_line(num[i][j],num[i][k],dis[i][j]+dis[i][k]);
			}
		}
	}
	while(T--){
		cin>>x>>y;
		ans=1e18;
		for(i=1;i<=cnt[x];i++){
			Dijstra(num[x][i]);
			for(j=1;j<=cnt[y];j++) ans=min(ans,f[num[y][j]]+e[y]+dis[y][j]+e[x]+dis[x][i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

//GZ-S00386 吴显鑫 
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int f[1000010];
bool v[1000010];
PII hp[1000010];
int l=0,r=-1;

long long ans;
int xr,yr;
int c,n,m,d,q;
int nt[1000010];
int to[1000010];
int h[1000010];
int w[1000010];
int idx;
int els[1000010];//从每个地铁站的地铁口走到站厅需要的时间
void add(int x,int y,int z) {
	to[idx]=y;
	nt[idx]=h[x];
	h[x]=idx;
	w[idx]=z;
	idx++;
}
long long djka(int u) {
	v[u]=true;
	hp[++r]=((PII){0,u});
	r++;
	while(l<=r) {
		int mi=-0x3f3f3f3f;
		int mis=0;
		for(int i=l;i<=r;++) {
			if(mi>hp[i].)
		}
		PII s=hp[++l];
		int x=s.second;
		int y=s.first;
		v[y]=true;
		for(int i=h[x];i=nt[i];i!=-1) {
			if(x+w[i]<f[i]) {
				f[i]=x+w[i];
				hp[++r]=(PII){f[i],i}; 
			}	
		}
	}
}
int main() {
	memset(f,0x3f,sizeof(f));
	freopen("subway.in","r",stdin);//注意等一下修改 
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>els[i];
	}
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int x,y;
			cin>>x>>y;//表示第 i 条线路经过的第 j 个地铁站， y表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
			add(i+m,x,y);
			add(x,i+m,y);
			
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>xr>>yr;
		ans=els[xr]+els[yr];
		ans+=djka(xr);
		return 0;		
	}
}







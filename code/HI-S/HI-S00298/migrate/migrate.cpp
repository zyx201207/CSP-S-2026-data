#include<bits/stdc++.h>
#define afor(i,x,y) for(int i=(x);i<=(y);i++)
#define bfor(i,x,y) for(int i=(x);i>=(y);i--)
using namespace std;
typedef long long ll;
const int N=2e6+10;
int C,T,n,l[N],r[N],fa[N],c[N],f[N];
ll ans,d,x[N],y[N],s[N],g[N];
vector<int> pl[N];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y) {
	x=find(x),y=find(y);if(x!=y) fa[y]=x;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--) {
		scanf("%d%lld",&n,&d),ans=0;
		afor(i,1,n) scanf("%lld",&x[i]),y[n-i+1]=-x[i];
		afor(i,1,n) {
			l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			r[i]=n-(lower_bound(y+1,y+n+1,-x[i]-d)-y)+1;
//			pl[l[i]].push_back(i),c[r[i]]++;
			if(i==r[i]) f[i]++;
			else f[r[i]]+=++f[i];
		}
//		afor(i,1,n) fa[i]=i;
//		afor(i,1,n) if(l[r[i]]==i) merge(i,r[i]);
//		afor(i,1,n) {
//			int x=find(i);
//			if(i!=x) c[x]+=c[i];
//			for(int j:pl[i]) f[j]=c[x]+j-l[j]+1;
//		}
		afor(i,1,n) s[r[i]]+=f[i];
		afor(i,1,n) if(l[i]<i) {
			g[i]=g[l[i]];
			if(l[i]+1<i) {
				ans+=g[i]+s[l[i]+1];
//				printf("> %d %d\n",i,g[i]+s[l[i]+1]);
				if(r[l[i]+1]==i) g[i]+=s[l[i]+1];
			}
//			printf("%d %d %d\n",i,s[i],g[i]);
		}
		printf("%lld\n",ans);
		afor(i,1,n) pl[i].clear(),c[i]=s[i]=g[i]=f[i]=0;
	}
	return 0;
}

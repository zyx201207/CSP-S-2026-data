#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int las[N*2],nex[N*2],cnt=0,h[N];
void add(int x,int y){
	las[++cnt]=y;
	nex[cnt]=h[x];
	h[x]=cnt;
}
int tt,t,n,k;
int fa[N];
int get(int x){
	if(x==fa[x]){
		return x;
	}
	fa[x]=get(fa[x]);
	return fa[x];
}
int f[100][100];
bool v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&tt,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			h[i]=0;
		}
		cnt=0;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		if(tt<=3){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					f[i][j]=n;
				}
				f[i][i]=0;
			}
			for(int i=1;i<=n;i++){
				for(int j=h[i];j!=0;j=nex[j]){
					f[i][las[j]]=1;
				}
			}
			for(long long kk=1;kk<=n;kk++){
				for(long long i=1;i<=n;i++){
					for(long long j=1;j<=n;j++){
						f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
					}
				}
			}
			int maxx=(1<<n);
			int ans=n;
			for(int s=1;s<maxx;s++){
				int tot=0;
				for(int j=1;j<=n;j++){
					fa[j]=j;
					if((s>>(j-1))&1){
						v[j]=true;
						tot++;
					}
					else{
						v[j]=false;
					}
				}
				if(tot!=k){
					continue;
				}
				for(int j=1;j<=n;j++){
					if(v[j]==true){
//						cerr<<j<<" - ";
						for(int i=h[j];i!=0;i=nex[i]){
							if(v[las[i]]){
								fa[get(las[i])]=get(j);
							}
						}
					}
				}
//				cerr<<endl;
				tot=0;
				for(int i=1;i<=n;i++){
					if(v[i]&&fa[i]==i){
						tot++;
					}
				}
				if(tot>=3){
					continue;
				}
				int res=0;
				for(int i=1;i<=n;i++){
					if(v[i]==true){
						continue;
					}
					int w=n;
					for(int j=1;j<=n;j++){
						if(v[i]!=v[j]){
							w=min(w,f[i][j]);
						}
					}
					res=max(res,w);
				}
				ans=min(ans,res);
			}
			printf("%d\n",ans);
		}
		else{
			printf("1\n");
		}
	}
	return 0;
}

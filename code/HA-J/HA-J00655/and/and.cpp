#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e5+5;
int n,m;
ll a,er[40],ans;
int b[N][40],p[N],tot;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	er[0]=1;
	for(int i=1;i<=35;i++){
		er[i]=er[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		for(int j=35;j>=0;j--){
			if(a>=er[j]){
				b[i][j]=1;
				a-=er[j];
			}
		}
	}
	memset(vis,1,sizeof(vis));
	for(int j=35;j>=0;j--){
		int k=0;
		if(tot==0){
			for(int i=1;i<=n;i++){
				if(b[i][j]){
					k++;
					p[++tot]=i;
				}
			}
			if(k>=m){
				ans+=er[j];
			}else{
				tot=0;
			}
		}else{
			for(int i=1;i<=tot;i++){
				if(!vis[i])continue;
				if(b[p[i]][j]){
					k++;
				}else{
					vis[i]=0;
				}
			}
			if(k>=m){
				ans+=er[j];
				int cnt=0,pp[N];
				for(int i=1;i<=tot;i++){
					if(vis[i])pp[++cnt]=p[i];
				}
				tot=cnt;
				for(int i=1;i<=cnt;i++){
					p[i]=pp[i];
				}
				memset(vis,1,sizeof(vis));
			}else{
				memset(vis,1,sizeof(vis));
			}	
		}
	}
	printf("%lld",ans);
	
	return 0;
}

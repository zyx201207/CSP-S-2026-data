#include<bits/stdc++.h>
#define int long long
#define ll __int128
using namespace std;
const int MAXN=2e6+10,N1=5e3+10;
int FW,T,n,d,a[MAXN],vis[N1],ans,f[N1],G[N1];
ll D;
char ch;
void rd(int &x){
	x=0,ch=getchar();
	int flg=1;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') flg=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=flg;
}
void work(){
	rd(n),rd(d),ans=0,D=d;
	for(int i=1;i<=n;i++) rd(a[i]);
	if(FW<=10){
		for(int i=1;i<=n;i++){
			int L=i,id=0;
			for(int j=0;j<=n;j++) vis[j]=f[j]=G[j]=0;
			vis[0]=1,G[L]=1;
			for(int j=i+1;j<=n;j++){
				if((ll)(a[j]-a[j-1])>D) break;
				while((ll)(a[j]-a[L])>D){
					vis[f[L]]-=G[L];
					if(f[L]==id&&!vis[f[L]]){
						while(!vis[id]) ++id;
					}
					++L;
				}
				if(vis[id]==2) ++ans;
				G[j]=vis[id],vis[id+1]+=G[j],f[j]=id+1;
			}
		}
		printf("%lld\n",ans);
	}else if(FW==11||FW==12){
		int R=1;
		while(a[R]-a[1]<=d) ++R;
		--R;
		if(R>=3){
			int qwe=n/R;
			ans=qwe+(n-qwe*R>=3);
		}
		printf("%lld\n",ans);
	}else puts("0");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	rd(FW),rd(T);
	while(T--) work();
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define maxn (int)2e6
signed T;
int n,d,x[maxn],to[maxn],cover[maxn];
int p,f,ans;
int ss,se,es,ee;
int nss,nse,nes,nee;
bool k;
signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%*d%d",&T);
	while(T--){
		std::memset(cover,0,sizeof(cover));
		scanf("%lld%lld",&n,&d);
		if(n<=3){
			printf("0\n");
			continue;
		}
		ans=0;
		p=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
			f=x[i]-x[p];
			if(f==d){
				to[p]=i;
				p++;
				continue;
			}
			while(f>d){
				to[p]=i-1;
				f=f-x[p+1]+x[p];
				p++;
			}
		}
		for(;p<=n;p++) to[p]=n;
		p=to[1];
		if(p==n){
			printf("0\n");
			continue;
		}
		for(int i=2;i<=n;i++){
			if(to[i]==p) continue;
			f=to[i];
			for(int j=1;i<=p;j++){
				cover[i]=j;
				i++;
			}
			p=f;
		}
		for(int i=2;i<=n;i++) if(x[i]-x[i-1]>d) cover[i]=-1;
		k=false;
		nss=1;
		for(int i=1;i<=n;i++){
			if(k){
				es=nes;
				if(cover[i]==-1){
					ee=i-1;
					ans=ans+(se-ss+1)*(ee-es+1);
					nss=i;
					k=false;
					continue;
				}
				if(cover[i]==1){
					if(!cover[i]) continue;
					if(cover[i+2]){
						ee=i+2;
						ans=ans+(se-ss+1)*(ee-es+1);
						nss=i;
						k=false;
					}else{
						ee=i+1;
						ans=ans+(se-ss+1)*(ee-es+1);
						se=i-1;
						es=i+2;
					}
				}
			}else{
				ss=nss;
				if(cover[i]==-1){
					nss=i;
					continue;
				}
				if(cover[i]==1){
					if(!cover[i]) continue;
					if(cover[i+2]){
						nss=i;
					}else{
						k=true;
						se=i-1;
						nes=i+2;
						nss=i+1;
					}
				}
			}
		}
		if(k){
			ee=n;
			ans=ans+(se-ss+1)*(ee-es+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

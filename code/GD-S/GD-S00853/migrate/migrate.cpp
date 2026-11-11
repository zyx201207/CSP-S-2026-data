#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
ll n,d;
ll tu[5005][5005];
ll a[5005];
ll cnt;
ll vis[5005];
queue<ll> b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		memset(tu,0,sizeof tu);
		memset(a,0,sizeof a);
		cnt=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(c<=6){
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d)break;
					tu[i][j]=1;
				}
			}
			for(int z=1;z<=n-3;z++){
				memset(vis,0,sizeof vis);
				for(int i=z+1;i<=n;i++){
					if(tu[z][i]){
						b.push(i);
						vis[i]=1;
					}
				}
				while(!b.empty()){
					ll ls=b.front();
					b.pop();
					for(int i=ls+1;i<=n;i++){
						if(tu[ls][i]!=0){
							if(tu[z][i]!=0){
								if(tu[z][ls]+1==tu[z][i])vis[i]+=vis[ls];
							}else{
								tu[z][i]=tu[z][ls]+1;
								vis[i]+=vis[ls];
								b.push(i);
							}
						}
					}
				}
				for(int i=z+1;i<=n;i++){
					if(vis[i]==2){
						cnt++;
					}
				}
			}
			printf("%lld\n",cnt);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


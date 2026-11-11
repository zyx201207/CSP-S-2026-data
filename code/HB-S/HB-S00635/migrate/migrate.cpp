#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n,cnt=0;
long long a[N],b[N],d,ans;
int e[N];
int mi=1e9,cas=0;
void dfs(int x,int goal,int res){
	if(cas>2)return;
	if(res>mi)return;
	int far=0;
	for(int i=x+1;i<=goal;i++){
		if(a[i]-a[x]>d){
			far=i-1;
			break;
		}
	}
	if(far==0){
		if(res<=mi){
			mi=res;
			cas++;
		}
		return;
	}
	for(int i=far;i>x;i--){
		dfs(i,goal,res+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		cnt=0,ans=0;;
		memset(e,0,sizeof(e));
		scanf("%d%lld",&n,&d);
		scanf("%lld",&a[1]);
		e[++cnt]=0;
		for(int i=2;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i-1]=a[i]-a[i-1];
			if(b[i-1]>d)e[++cnt]=i-1;
		}
		e[++cnt]=n;
		for(int o=1;o<cnt;o++){
			for(int i=e[o]+1;i<=e[o+1];i++){
				for(int l=4;l+i-1<=e[o+1];l++){
					int j=l+i-1;
					mi=1e9,cas=0;
					dfs(i,j,0);
					if(cas==2){
						ans++;
					}	
				}
			}
		}
		printf("%lld\n",ans);
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

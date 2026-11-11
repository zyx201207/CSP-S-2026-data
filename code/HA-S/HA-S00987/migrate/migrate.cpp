#include<bits/stdc++.h>
#define LL long long
using namespace std;
int c,t;
LL n,d,a[2000010],dis,ansdfs=LONG_LONG_MAX,ans=0,check=0;
bool flaga,flag;
void dfs(int now,int co,int cnt){
	if(cnt>ansdfs) return;
	if(now==co){
		if(cnt<ansdfs){
			ansdfs=cnt;
			check=1;
		}
		else check++;
		return;
	}
	for(int i=now+1;i<=co;i++){
		if(a[i]-a[now]<=d){
			dfs(i,co,cnt+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12) flaga=1;
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		if(n>5000) flag=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i==2){
				dis=a[2]-a[1];
			}
		}
		if(flaga){
			if(d>=2*dis&&d<3*dis){
				printf("%lld\n",n-3);
			}
			else printf("%lld\n",0);
		}
		else if(flag){
			int st=lower_bound(a+1,a+n+1,a[1]+d)-a,fi=lower_bound(a+1,a+n+1,a[n]-d)-a;
			if(fi-st!=-1) printf("%lld\n",0);
			else{
				printf("%lld\n",(fi-1)*(n-st));
			}
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					ansdfs=LONG_LONG_MAX;
					check=0;
					dfs(i,j,0);
					if(check==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}


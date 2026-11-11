#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
int c,T;
const int MAXN=2e6+5;
ll x[MAXN],d;
int n,l[MAXN];
int siz[MAXN][3][2];
ll read(){
	ll num=0;char c=getchar();
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	int opt=1;
	if(c=='-'){
		opt=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*opt;
}
void did(){
	scanf("%d%lld",&n,&d);
	int now=1;l[0]=0;
	for(int i=1;i<=n+2;i++)l[i]=n+2;
	ll ans=0;
	for(int i=1;i<=n;i++){
		x[i]=read();
		while(now<i&&x[i]-x[now]>d){
			now++;
		}
		l[i]=now;
		if(l[i]==i)continue;
		siz[l[i]][1][0]++;
	}
	for(int t=n;t>=1;t--){
		for(int j=1;j<=2;j++){
			for(int k=0;k<2;k++){
				if(!siz[t][j][k])continue;
				int typ=j;bool lst=k;
				int tt=l[t],tt1=l[t+1],tt2=l[t+2];
				if(tt==tt1){
					typ++;
					if(lst)typ++;
					if(tt2==tt)typ++;
					if(typ==2){
						ans+=(min(tt2,t)-tt)*1ll*siz[t][j][k];
						siz[tt][typ][lst]+=siz[t][j][k];
					}
				}else{
					if(typ==1){
						if(tt1<t&&!lst)ans+=(min(tt2,t)-tt1)*1ll*siz[t][j][k];
					}else{
						ans+=(min(tt1,t)-tt)*1ll*siz[t][j][k];
					}
					lst=(x[t+1]-x[tt+1]<=d&&tt+1!=t);
					siz[tt][typ][lst]+=siz[t][j][k];
				}
				siz[t][j][k]=0;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		did();
	}
}

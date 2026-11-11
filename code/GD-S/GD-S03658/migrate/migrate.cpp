#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
template<typename T>
void read(T &x){
	char ch=getchar();bool fg=0;x=0;
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') fg=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=(fg?-x:x);
	return ;
}
ll n,m,k,z,x,s,p,d;
ll pos[2000005];
ll f[2000005],g[2000005];
ll tg[2000005];
int t;
ll sm,cnt,ans;
void work(){
	ans=0;
	read(n),read(d);
	for(int i=1;i<=n;i++) read(pos[i]);
	for(int st=1;st<=n;st++){
		for(int i=1;i<=n;i++) f[i]=n+1,g[i]=1,tg[i]=0;
		f[st]=0,t=st,sm=0,tg[0]=1;
		for(int i=st+1;i<=n;i++){
			while(pos[i]-pos[t]>d) tg[f[t]]-=g[t],t++;
			while(sm<=n&&tg[sm]==0) sm++;
			if(sm>n) break;
			f[i]=sm+1,g[i]=tg[sm];
			if(g[i]==2){
				ans++;
			}
			tg[f[i]]+=g[i];
		}
	}
	printf("%lld\n",ans);
	return ;
}
void work2(){
	ans=0;
	read(n),read(d);
	for(int i=1;i<=n;i++) read(pos[i]);
	if(n==1){
		printf("0\n");
		return ;
	}
	s=d/(pos[2]-pos[1]);
	if(s<=1) printf("0\n");
	else{
		ans=max(0ll,n-2*s+1);
		printf("%lld\n",ans);
	}
	return ;
}
void work3(){
	ans=0;
	read(n),read(d);
	for(int i=1;i<=n;i++) read(pos[i]);
	for(int i=1;i<=n;i++){
		if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d){
			x=i;
			break;
		}
	}
	ll l1=1,l2=x,r1=x,r2=n;
	if(x<n){
		for(int i=1;i<=n;i++)
			if(pos[x+1]-pos[i]<=d){
				l1=i;break;
			}
	}
	if(x<n-1){
		for(int i=1;i<=n;i++){
			if(pos[x+2]-pos[i]<=d){
				l2=i;break;
			}
		}
	}
	if(x>1){
		for(int i=n;i>=1;i--){
			if(pos[i]-pos[x-1]<=d){
				r2=i;break;
			}
		}
	}
	if(x>2){
		for(int i=n;i>=1;i--){
			if(pos[i]-pos[x-2]<=d){
				r1=i;break;
			}
		}
	}
	ans=(l1-1)*(r2-r1)+(l2-l1)*(n-r2);
	printf("%lld\n",ans);
	return ;
}
int main(){
	//migrate
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tid,tz;
	read(tid),read(tz);
	if(tid==11||tid==12){
		while(tz--) work2();
	}
	else if(tid==13||tid==14){
		while(tz--) work3();
	}
	else
		while(tz--) work();
	return 0;
}
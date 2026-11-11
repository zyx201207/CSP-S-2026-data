#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=2e6+5;
int optt,T;
int n,d;
int a[Maxn],pre[Maxn],nxt[Maxn];
int f[Maxn][2][2];
inline void solve(){
	n=read();d=read();
	for(int i=0;i<=n+1;i++)memset(f[i],0,sizeof f[i]);
	for(int i=1;i<=n;i++)a[i]=read();
	int p=n;
	for(int i=n;i;i--){
		while(a[p]-a[i]>d)p--;
		nxt[i]=p;
	}
	p=1;
	for(int i=1;i<=n;i++){
		while(a[i]-a[p]>d)p++;
		pre[i]=p;
	}
	
//	for(int i=1;i<=n;i++){
//		printf("nxt[%d]=%d\n",i,nxt[i]);
//	}
//	puts("");
//	for(int i=1;i<=n;i++){
//		printf("pre[%d]=%d\n",i,pre[i]);
//	}
	
	for(int u=1;u<=n;u++){
		int tp=nxt[u];
		if(tp==u)continue;
		if(pre[tp]<=u)f[tp][0][0]++;
		if(pre[tp-1]<=u)f[tp][1][1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j:{0,1})for(int k:{0,1}){
			if(j<k)continue;
			int tp=nxt[i],tp1=i,tp2=i-k;
			if(tp==i)continue;
			if(pre[tp]==tp2){
				f[tp][j][0]+=f[i][j][k];
			}
			if(!j&&pre[tp-1]==tp2){
				f[tp][1][1]+=f[i][j][k];
			}
		}
	}
	int ans=0;
	for(int v=2;v<=n;v++){
		for(int j:{1})for(int k:{0,1}){
			if(j<k)continue;
			if(pre[v]+k<v){
				ans+=f[pre[v]+k][j][k];
//				printf("v=%d,[%d,%d,%d]:%d\n",v,pre[v]+k,j,k,f[pre[v]+k][j][k]);
			}
		}
	}
	printf("%lld\n",ans);
	
	
//	for(int u=1;u<n;u++){
//		for(int v=u+1;v<=n;v++){
//			vector<int>a,b;
//			int p=nxt[u];bool chk=1;
//			while(p<v){
//				a.push_back(p);
//				if(nxt[p]>p)p=nxt[p];
//				else{chk=0;break;}
//			}
//			if(!chk)continue;
//			p=pre[v];
//			while(u<p){
//				b.push_back(p);
//				if(pre[p]<p)p=pre[p];
//				else{chk=0;break;}
//			}
//			if(!chk)continue;
//			reverse(b.begin(),b.end());
//			int sum=0;
////			printf("{%d,%d}\n",a.size(),b.size());
////			for(int i=0;i<a.size();i++)printf("gfregreg [%d,%d]\n",a[i],b[i]);
//			for(int i=0;i<a.size();i++)sum+=(a[i]-b[i]),assert(a[i]>=b[i]);
//			if(sum==1){
//				printf("right!  (%d,%d)\n",u,v);
//			}
//		}
//	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	optt=read();T=read();
	while(T--)solve();
	return 0;
}//16:13
/*
0 1
6 3
0 1 2 3 4 7
ans:0

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
ans:6
*/

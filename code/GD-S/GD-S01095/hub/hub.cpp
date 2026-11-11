#include<bits/stdc++.h>
using namespace std;
namespace IO{
	template<typename T>void read(T &x){short f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;return;}
	template<typename T>void out_(T x){if(x>9) out_(x/10);putchar(x%10+'0');return;}
	template<typename T>void out(T x){if(x<0) putchar('-'),x=-x;out_(x),putchar(' ');return;}
	void endl(){putchar('\n');return;}
}using namespace IO;
const int N=1e6+5,inf=1e9;
int Tid,T,n,k;
vector<int>e[N];
//bitset<5005>reach[N],s1,s2,s3,s4;
//void dfs(int from,int x,int fa,int dep,int lim){ //维护可达性 
//	reach[from][x]=1;
//	if(dep==lim) return;
//	for(int u:e[x]){
//		if(u==fa) continue;
//		dfs(from,u,x,dep+1,lim);
//	}
//	return;
//}
//bool did;
//void dfs1(int x,int fa){
//	s3&=reach[x];
//	s1[x]=1;
//	for(int u:e[x]){
//		if(u==fa) continue;
//		dfs1(u,x);
//	}
//	return;
//}
//void dfs2(int x,int fa){
//	s4&=reach[x];
//	s2[x]=1;
//	for(int u:e[x]){
//		if(u==fa) continue;
//		dfs2(u,x);
//	}
//	return;
//}
//void Dfs(int x,int fa){
//	for(int u:e[x]){
//		if(u==fa) continue;
//		//考虑割掉这条边 
//		s1=s2=0;
//		for(int i=1;i<=n;i++) s3[i]=s4[i]=1;
//		dfs1(x,u),dfs2(u,x); 
//		s3&=s1,s4&=s2;
//		if(x==2&&u==3){
//			printf("fkasdhfjsdhfkfdskafhjasf\n");
//			for(int i=1;i<=n;i++) cout<<s3[i];
//			exit(0);
//		}
//		if((int)s3.count()+(int)s4.count()<=k) did=1;		
//		Dfs(u,x);
//	}
//	return;
//}
//bool check(int s){
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++) 
//			reach[i][j]=0;
//	for(int i=1;i<=n;i++) dfs(i,i,0,0,s);
//	//cut
//	did=0;
//	Dfs(1,0);
//	return did;
//}
bool did;
int minn,id;
int siz[N],Sz[N];
void Dfs(int x,int fa,int s){
	siz[x]=1;
	int maxn=0;
	for(int u:e[x]){
		if(u==fa) continue;
		Dfs(u,x,s);
		siz[x]+=siz[u];
		maxn=max(maxn,siz[u]);
	}
	maxn=max(maxn,s-siz[x]);
	if(minn>maxn){
		minn=maxn;
		id=x;
	}
	return;
}
int dp[N],Fa[N];
void Do(int x,int fa,int who,int lim){
	dp[x]=0;
	Fa[x]=fa;
	int son=0,res=0;
	for(int u:e[x]){
		if(u==fa||u==who) continue;
		Do(u,x,who,lim);
		res+=dp[u];
		son++;
	}
	if(son==0){
		int tmp=x;
		for(int _=1;_<=lim;_++) tmp=Fa[tmp];
		if(tmp) dp[tmp]=1;
	}
	if(fa==0||res){ //说明是根 
		dp[x]=1;
	}
	dp[x]+=res;
	return;
}
int solve(int x,int fa,int lim,int s){
	//找重心 
	minn=id=inf;
	Dfs(x,fa,s);
	Do(id,0,fa,lim);
	return dp[id];
}
void dfs(int x,int fa,int lim){
	Sz[x]=1;
	for(int u:e[x]){
		if(u==fa) continue;
		dfs(u,x,lim);
		if(did==1) return;
 		Sz[x]+=Sz[u];
		int tmp=solve(x,u,lim,n-Sz[u])+solve(u,x,lim,Sz[u]);
		if(tmp<=k){
			did=1;
			return;
		}
	}
	return;
}
bool check(int s){
	did=0;
	dfs(1,0,s); //cut
	return did;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	read(Tid),read(T);
	while(T--){
		read(n),read(k);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			read(x),read(y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(Tid>=13&&Tid<=14){
			int m=n/2,len=m+2;
			if(len%2==0) out(len/2-k/2),endl();
			else{
				if(k%2==1) out(len/2-(k-1)/2),endl();
				else out(len/2-(k-2)/2),endl();				
			}
			continue;
		} 
//		int l=0,r=n,res=n;
//		while(l<=r){
//			int mid=(l+r)>>1;
//			if(check(mid)) res=mid,r=mid-1;
//			else l=mid+1;
//		}
//		out(res),endl();
		int l=0,r=n,res=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)) res=mid,r=mid-1;
			else l=mid+1;
		}
		out(res),endl();
	}
	return 0;
}

//是不是可以考虑枚举一条边钦定其断开，然后分开做？

//对于每一边，找到其重心，然后扩展

//考虑二分然后能够想到一个 n^2 状物，大概是 n^2log(n)/w ???

//预计6:00写完 

//做法好像假了

//二分，找重心，然后扩展，这个应该是对的，时间有点紧了 

//17:53 收工应该有 50~58pts 

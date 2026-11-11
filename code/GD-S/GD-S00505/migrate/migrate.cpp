#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int testid,T;
int n,m,a[2000006];
int fd(int x,int l=1,int r=n){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>x)r=mid-1;
		else l=mid+1;
	}
	return r;//<=x
}
int dis[2000006],level[2000006];
int lvfd(int x,int l=1,int r=n){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(level[mid]>x)l=mid+1;
		else r=mid-1;
	}
	return r;//>x
}
int val[2000006];
inline int lowbit(int x){
	return x&(-x);
}
void add(int x,int a){
	for(int i=x;i<=2000001;i+=lowbit(i))val[i]+=a;
}
int query(int x){
	int sum=0;
	for(int i=x;i;i-=lowbit(i))sum+=val[i];
	return sum;
}

int solve(int s){
	//if(s%1000==0)cerr<<"Solve:"<<s<<"\n";
	int ans=0,la=n;
	for(int i=s;i>=1;--i){
		level[i]=dis[i]=0;
	}
	for(int i=1;i<=2000001;++i){
		val[i]=0;
		if(i>s&&lowbit(i)==i)break;
	}
	dis[s]=1;
	add(s,1);
	int ban=0;
	for(int i=s-1;i>=1;--i){
		int ffd=fd(a[i]+m,i,s);
		//cerr<<i<<":"<<ffd<<"\n";
		if(ffd==i)return ans;
		level[i]=level[ffd]+1;
		if(dis[i+1]>=3&&level[i]!=level[i+1])break;
		if(level[i]!=level[i+1]&&ban!=0){
			i=ban+1;
			ban=0;
			continue;
		}
		int lfd=lvfd(level[ffd],i,s);
		dis[i]=query(ffd)-query(lfd);
		add(i,dis[i]);
		//cerr<<"dis:"<<dis[i]<<"\n";
		if(dis[i]==2)++ans;
		if(dis[i]>3){
			if(ban==0)ban=fd(a[i]-m,1,i);
			else ban=min(ban,fd(a[i]-m,1,i));
		}
		
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	testid=read();
	T=read();
	while(T--){
		n=read();
		m=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=n;i>=1;--i){
			ans+=solve(i);
		}
		printf("%lld\n",ans);
	}
}
/*
1 2
5 3
-3 0 2 3 4
6 120
-100 -60 -20 20 60 100
ans:2
(1,5)
(2,5)
*/


#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e6+10;

inline ll read(){
	char ch=getchar();
	bool w=false;
	while(!isdigit(ch)){
		w|=ch=='-';
		ch=getchar();
	}
	ll x=0;
	while(isdigit(ch)){
		x=x*10ll+ch-'0';
		ch=getchar();
	}
	return w?-x:x;
}
int n,cnt[maxn];
ll x[maxn],d;

inline void solve(){
	scanf("%d%lld",&n,&d);
	rep(i,1,n) x[i]=read();
	if(n>5002) return puts("..."),void();
	int res=0;
	rep(i,1,n){
		rep(j,i,n) cnt[j]=0;
		int j=i,p1=0,p2=0,p3=0;
		while(j<n && x[j+1]-x[i]<=d) j++;
		rep(k,i,j) cnt[k]=1;
		p3=j;
		if(j-1>=i) p2=j-1;
		if(j-2>=i) p1=j-2;
//		printf("# %d %d %d\n",i,i,j);
		while(j<n){
			j++;
			int lst=j;
			if(p1 && x[j]-x[p1]<=d) cnt[j]+=cnt[p1];
			if(p2 && x[j]-x[p2]<=d) cnt[j]+=cnt[p2];
			if(p3 && x[j]-x[p3]<=d) cnt[j]+=cnt[p3];
			res+=cnt[j]==2; 			
			while(j<n && x[j+1]-x[p3]<=d){
				j++;
//				printf("## %d %d %d %d\n",j,p1,p2,p3);
				if(p1 && x[j]-x[p1]<=d) cnt[j]+=cnt[p1];
				if(p2 && x[j]-x[p2]<=d) cnt[j]+=cnt[p2];
				if(p3 && x[j]-x[p3]<=d) cnt[j]+=cnt[p3];
				res+=cnt[j]==2; 
			}
			p3=j;
			if(j-1>=lst) p2=j-1;
			else p2=0;
			if(j-2>=lst) p1=j-2;
			else p1=0;
//			printf("# %d %d %d\n",i,lst,j);
		}
//		puts("cnt");
//		rep(j,1,n) printf("%d%c",cnt[j]," \n"[j==n]);
	}
	printf("%d\n",res);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_=1;
	scanf("%d%d",&c,&_);
	while(_--) solve();
}


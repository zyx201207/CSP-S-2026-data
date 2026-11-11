//最短路径恰好两条：
//恰有两种选点方案，它们的个数相同，且不存在任何一种小于它们选点个数的方案
//考虑传递性：若(u,v)为双径岛屿对，则必存在L<=v<=R，使得(u,L)至(u,R)为双径岛屿对
//性质A：最大飞行岛屿数固定，为k。

//其中一种最短路一定是每次飞最远（确定最短路m） 
//然后问题形如将区间分为m-1个点，使得每个区间的端点之差<=d的方案数 
//若是固定左端点，则右端点的变化只影响从最后一个点飞到右端点，且m递增 
//故N*N dp
//f[i][j]表示考虑r=i，分成j段的方案数
//f[i][j]=f[k-1][j-1]*[k,i]可直飞
//可拿24

//考虑变为N*N
//f[i]表示考虑r=i的方案数
//f[i]=f[k-1]*[k,j]可直飞
//然后又可以得出临界的k，然后dp前缀和即可，能拿40
//再来个性质A直接48到手 

#include<bits/stdc++.h>
#define int long long
const int N=2e6+10;

//inline int read(){
//	int x=0,f=1;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-') f=-1;
//		ch=getchar();
//	}
//	while('0'<=ch&&ch<='9'){
//		x=x*10+(ch-'0');
//		ch=getchar();
//	}
//	return x*f;
//}
//inline void print(int x){
//	if(x<0) putchar('-'),x=-x;
//	if(x>9) print(x/10);
//	putchar(x%10+'0');
//	return ;
//}

int n,d;
int x[N];
int f[N]; 
int pre[N],nxt[N];
int ans=0,cd=0;

void solve(){
	memset(f,0,sizeof f);
	memset(pre,0,sizeof pre);
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	if(n==1){
		std::cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f);
		memset(pre,0,sizeof pre);
		f[i]=1;
		pre[i]=1;
		for(int r=i+1;r<=n;r++){
			int limit_l=std::lower_bound(x+i,x+n+1,x[r]-d)-x;
			int min_dis=(x[r]-x[i]+d-1)/d;
			int limit_r=std::lower_bound(x+i,x+n+1,x[i]+(min_dis-1)*d)-x;
			f[r]=pre[limit_r]-pre[limit_l-1];
			pre[r]=pre[r-1]+f[r];
		}
		for(int r=i;r<=n;r++){
			if(f[r]==2) ans++;
		}
	}
	printf("%lld\n",ans);
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		solve();
	}
	fclose(stdin);
//	freopen("test.txt","w",stdout);
//	if(system("fc migrate.out migrate1.ans >nul")){
//		std::cout<<"WA"<<'\n';
//	}
//	else{
//		std::cout<<"AC"<<'\n';
//	}
	fclose(stdout);
	return 0;
} 
 

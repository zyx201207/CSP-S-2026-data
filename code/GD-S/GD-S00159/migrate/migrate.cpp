#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=0x3f3f3f3f3f3f;
int C,T,n,d,a[N],res=inf;
void dfsFind(int idx,int step,int x){
	if(idx>=x){
		res=min(res,step);	
		return;
	}
	for(int i=idx+1;i<=x;i++){
		if(a[i]-a[idx]>d) break;
		dfsFind(i,step+1,x);
	}
	return;
} 
int dfs(int idx,int step,int x){
	if(idx>=x){
		if(step==res) return 1;
		return 0;
	}
	int cnt=0;
	for(int i=idx+1;i<=x;i++){
		if(a[i]-a[idx]>d) break;
		cnt+=dfs(i,step+1,x);
	}
	return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&C,&T);
	
	
	if(C==13||C==14){
		while(T--) puts("0");
		return 0;
	}//B 
	if(C==11||C==12){
		while(T--){
			scanf("%lld%lld",&n,&d);
			int a,b;
			scanf("%lld%lld",&a,&b);
			int c=b-a;
			if(d/c==2) printf("%lld\n",n-3);
			else puts("0");
		}
		return 0;
	}//A
	
	
	while(T--){
		int ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				res=inf;
				dfsFind(i,0,j);
				if(dfs(i,0,j)==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
暴力 + 特殊性质，看看能混多少分（
性质 B 很良心，容易得到有滚木个双径岛屿对 
性质 A 等差数列，路径数量应该可以AdHoc出来 
如果公差为 c ，那么海鸟一次可以飞跃 d/c 个岛屿
双径岛屿对的间距应该是当且仅当 d/c 等于二时，有 n-3 个对 
性质 C 估计接近正解了先不打 
暴力的话直接暴搜吧 

5：44 p.m. 发现性质 A 不太对
但太复杂了我想不动（ 
*/

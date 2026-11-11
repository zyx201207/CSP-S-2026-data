#include<bits/stdc++.h>
using namespace std;
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define rrep(x,y,z) for(int x=z;x>=y;x--)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=2e5+5;

//Chtholly bless me

//09:55 read T3,wtf Trie?
//10:04 done thinkin'
//10:07 doing Trie
//10:14 Is the person next to me a XiaoZili?
//10:15 So noisy
//10:23 turn to BruteForce
//10:25 will BinAns correct?
/*
Thinking again

while and more a_i,the best answer would not grow

try it,if it's wrong,big sample will tell me
*/
//10:38 F,WA
//Turn to DFS?
//10:47 Turn to DP?
//10:57 Snickers
//11:05 N^3 DP,I wonder if author is a normal human

int n,m;
int a[MAXN];
int dp[MAXN];

/*
int dfs(int cur,int cnt){//cur must be chosen,has chosen cnt of a[...]
	if(cnt>m)return 0xffffffff;
	int res=-1;
	rep(i,cnt+1,n){
		res=max(res,a[i]&dfs(i,cnt+1));
	}
	return res;
}
*/

void solve1(){
	int res=-1;
	
	rep(k,2,m){
		rrep(i,k,n){
			dp[i]=-1;
			rep(j,k-1,i){
				dp[i]=max(dp[i],dp[j]&a[i]);
			}
		}
	}
	
	rep(i,m,n){
		res=max(dp[i],res);
	}
	
	printf("%d\n",res);
}


int popcount(int x){
	int i=0;
	for(;x;i++,x&=x-1);
	return i;
}

int main(){
	#ifndef off
	qwq("and");
	#endif
	
	bool flagA=1,flagB=1,flagC=1;
	
	scanf("%d %d",&n,&m);
	flagB=(n==(n&(-n)));
	rep(i,1,n){
		scanf("%d",a+i);
		dp[i]=a[i];
		flagA=flagA&&(a[i]+1==(a[i]+1)&(-(a[i]+1)));
		flagB=flagB&&(a[i]==i-1);
		flagC=flagC&&(a[i]<=1024);
	}
	
	if(1ll*n*n*m<=2e8){
		solve1();
		return 0;
	}else if(m==1){
		int res=-1;
		rep(i,1,n){
			res=max(a[i],res);
		}
		printf("%d\n",res);
	}else if(m==n){
		int res=0xffffffff;
		rep(i,1,n){
			res&=a[i];
		}
		printf("%d\n",res);
	}else if(flagA){
		sort(a+1,a+n+1);
		int res=0xffffffff;
		rrep(i,n-m+1,n){
			res&=a[i];
		}
		printf("%d\n",res);
	}else if(flagB){
		priority_queue<pii,vector<pii>,less<pii> >q;
		rep(i,1,n){
			q.push({popcount(a[i]),a[i]});
		}
		int res=0xffffffff;
		rep(i,1,m){
			res&=q.top().se;
			q.pop();
		}
		printf("%d\n",res);
	}else puts("0");
}

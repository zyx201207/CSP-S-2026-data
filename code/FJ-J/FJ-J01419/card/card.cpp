#include<bits/stdc++.h>
using namespace std;
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define rrep(x,y,z) for(int x=z;x>=y;x--)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=5e5+5,MAXM=3e5+5;

//Chtholly bless me

//11:32 I HAVE NO TIME
//11:54 I HAVE NO TIME
//11:57 I HAVE NO TIME
//11:58 give up 

int n,m,a[MAXN];
int psame[MAXN],buck[MAXN];
bool vis[MAXN];
bool ans[MAXN];
int suff[MAXN];

/*
思路：
一张卡牌留在场上，要求右侧没有值相同的卡牌； 
值相同的卡牌仅处理最右侧的即可 

桶标记每个值的最后出现位置
另一个桶标记每个位置最靠右的相同值
后缀max处理每个位置右侧所有卡牌可能相同位置的最靠右者 
*/

int main(){
	
	#ifndef off
	qwq("card");
	#endif
	
	scanf("%d %d",&n,&m);
	rep(i,1,n){
		scanf("%d",a+i);
		psame[i]=buck[a[i]];
		buck[a[i]]=i;
	}
	
	rrep(i,1,n){
		suff[i]=max(suff[i+1],psame[i]);
	}
	
	#ifdef debug
	rep(i,1,n)printf("%d ",psame[i]);
	puts("");
	#endif
	
	rrep(i,1,n){
		if(vis[a[i]])continue;
		vis[a[i]]=1;
		if(suff[i+1]>i)continue;
		ans[a[i]]+=i;
	}
	
	rep(i,1,m)printf("%d ",ans[i]); 
}

#include <bits/stdc++.h>

#define fr for
//#define int long long

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

using namespace std;

const int N=5e5+7;

/*
都 2026 年了，我怎么还在考 J 组？

qwertyuiop[]\asdfghjkl;'
zxcvbnm,./`

我是 **，在 T2 花了 1h

必须在1h内解决T4否则我就是***

首先他首次出现的时候一定能存货！

然后消除的作用是跳过一段区间

bitset 优化 dp 有 88pts
？

10 3
3 1 2 1 3 2 3 1 2 1

以上全是发电，求子树大小即可 

我去我过了所有大洋里
 
 AK！！！！！！！！！！！！！！！！！！！！！！！！！！ 
*/
int las[N],add[N],a[N];
int mp[N],s[N];//某个数值对应哪个点 
vector<int>G[N];

void dfs(int u,int fa){
	s[u]=1;
	fr(auto v:G[u]){
		dfs(v,u);
		s[u]+=s[v];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout) ;
	int n=read(),m=read();
	fr(int i=1;i<=n;i++)a[i]=read();
	fr(int i=1;i<=n;i++){
		las[a[i]]=i;
	}
	mp[a[n]]=n;
	fr(int i=1;i<=n;i++){
		if(i==n)continue;
		if(las[a[i]]==i){
			mp[a[i]]=i;
			G[i+1].push_back(i);
		}
		else G[las[a[i]]].push_back(i);
	}
	dfs(n,0);
	fr(int i=1;i<=m;i++){
		printf("%d",s[mp[i]]);
		putchar(" \n"[i==m]);
	}
	return 0;
}


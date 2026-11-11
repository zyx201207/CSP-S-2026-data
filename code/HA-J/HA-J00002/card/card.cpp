#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =5e5+5;
int n,m,a[N],stk[N],top,ed[N],lst[N],nxt[N],t[N]; bool in[N],s1=1;
inline int lwb(int x){
	return x&-x;
}
inline void add(int x,int v){
	for(;x<N;x+=lwb(x))t[x]+=v;
}
inline int qry(int x){
	int res=0;
	for(;x;x-=lwb(x))res+=t[x];
	return res;
}
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("card");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i],ed[a[i]]=i;
	for(int i=n;i>=1;--i)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=1;i<n;++i)s1&=a[i]<=a[i+1];
	if(s1){
		for(int i=1;i<=m;++i)cout<<ed[i]<<" \n"[i==m];
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;){
			if(nxt[j])add(j,1),add(nxt[j],-1),j=nxt[j];
			else ++j;
		}
	}
	
	for(int i=1;i<=m;++i)cout<<ed[i]-qry(ed[i])<<" \n"[i==m];
	return 0;
}

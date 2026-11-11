#include<bits/stdc++.h>
using namespace std;
#define ll long long  
#define oF(l,r,i) for(int i=l;i<=r;i++) 
#define of(l,r) for(int i=l;i<=r;i++) 
#define tF(n,i) oF(1,n,i)
#define tf(n) oF(1,n,i)
#define nF(i) oF(1,n,i)
#define nf() oF(1,n,i)
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define file(x) (fin(x),fout(x),0)
inline ll read(){
	ll x=0;
	short f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c==45)f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
void write(ll x){
	if(x<0)x=~x+1,putchar(45);
	if(x>9)write(x/10);
	putchar(x%10|48);
}
int File=file(hub);
int CID=read(),T=read(),n,cnt;
basic_string<int>G[1000005];
int len[1000005],slen[1000005];
void dfs(int x,int fa=0){
	len[x]=1,slen[x]=0;
	for(int t:G[x])if(t^fa){
		dfs(t,x);
		if(len[t]>=len[x])slen[x]=len[x],len[x]=len[t]+1;
		else if(len[t]>=slen[x])slen[x]=len[t]+1;
	}
}
void pushd(int x,int fa=0){
	for(int t:G[x])if(t^fa){
		int L=len[x]==len[t]+1?slen[x]:len[x];
		if(L>=len[t])slen[t]=len[t],len[t]=L+1;
		else if(L>=slen[t])slen[t]=L+1;
		pushd(t,x);
	}
}
int SUM[1000005];
int C;
int l[1000005];
int f[1000005];
basic_string<int>L[1000005];
void lift(int lim,int x,int fa=0){
	for(int t:G[x])if(t^fa){
		if(slen[t]>=lim){
			lift(lim,t,x);
			l[x]=min(l[x],l[t]+1);
		}
	}
}
int mxl;
void down(int lim,int x,int fa=0){
	for(int t:G[x])if(t^fa){
		if(slen[t]>=lim){
			l[t]=min(l[t],l[x]+1);
			down(lim,t,x);
			mxl=max(l[t]+l[x],mxl);
		}
	}
}
int count(int V){
	tf(V)L[i].clear();
	nf()if(slen[i]>V){
		int cnt=0,val=V;
		for(int t:G[i])if(slen[t]<=V){
			val=min(val,V-slen[t]);
		}
		else cnt++;
		l[i]=cnt==2?val:0;
		if(l[i])L[l[i]]+=i;
	}
	nf()f[i]=0;
	mxl=0;
	lift(V,C);
	down(V,C);
	return SUM[V]-mxl;
}
signed main(){
	while(T--){
		n=read(),cnt=read();
		nf()G[i].clear();
		tf(n-1){
			int x=read(),y=read();
			G[x]+=y;G[y]+=x;
		}
		dfs(1);
		pushd(1);
		nf()SUM[i]=0;
		nf()SUM[slen[i]-1]+=1;
		for(int i=n-1;~i;i--)SUM[i]+=SUM[i+1];
		C=max_element(slen+1,slen+n+1)-slen;
		int l=0,r=slen[C];
		while(l<r){
			int mid=l+r>>1;
			if(count(mid)<=cnt)r=mid;
			else l=mid+1;
		}
		write(l);putchar(10);
	}
}

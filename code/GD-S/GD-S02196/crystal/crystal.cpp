#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,INF=1e18;
long long read(){
	int x=0,sign=1;char opt=getchar();
	while(opt<'0'||opt>'9'){
		if(opt=='-'){sign=-1;}
		opt=getchar();
	}
	while(opt>='0'&&opt<='9'){
		x=x*10+(opt-'0');
		opt=getchar();
	}
	return sign*x;
}
long long n,m,a[N],pre[N],ans=1,l,r;
bool check(int x,int len){
	if(len*a[x]-(pre[x]-pre[x-len-1])<=m){return 1;}
	else{return 0;}
}
long long slove(int x){
	long long l=0,r=x,lim=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(x,mid)){lim=mid;l=mid+1;}
		else{r=mid-1;}
	}
	return lim;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){a[i]=read();}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){pre[i]=pre[i-1]+a[i];}
	for(int i=2;i<=n;i++){ans=max(ans,slove(i));}
	printf("%lld",ans);
	return 0;
}

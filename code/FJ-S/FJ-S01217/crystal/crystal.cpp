#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=1e6+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n,m,a[N],sum[N],st[N][31];
//st[i][j]=max[i,i+(1<<j)-1];
void build(){
	for(int j=0;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			if(j==0)st[i][j]=a[i];
			else st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	int len=log2(r-l+1);
	return max(st[l][len],st[r-(1<<len)+1][len]);
}
bool check(int x){
	for(int r=x;r<=n;r++){
		int l=r-x+1;
		int MAX=query(l,r);
		int d=MAX*x-(sum[r]-sum[l-1]);
		if(d<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	build();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			res=mid;
		}
		else r=mid-1;
	}
	write(res);
	return 0;
}
/*
10 5
3 2 -5 1 2 10 6 -8 9 1

*/

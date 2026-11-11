#include<bits/stdc++.h>
#define N 500005
#define int long long
#define db double
#define ul unsigned long long
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define rf(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
int T,n,m,k,op,x,y,z,ans,lst;
int a[N],b[N];
void ckmax(int &x,int y){if(y>x)x=y;}
void ckmin(int &x,int y){if(y<x)x=y;}
bool ck(int x){
	for(int i=1,j=x;j<=n;i++,j++){
		int y=a[j]*x-(b[j]-b[i-1]);
		if(y<=m)return 1;
	}
	return 0;
}
int read(){
	int sum=0;bool f=0;char c=getchar();
	for(;c<48||c>57;c=getchar())if(c==45)f=1;
	for(;c>=48&&c<=57;c=getchar())sum=sum*10+(c&15);
	return f?-sum:sum; 
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	n=read();m=read();
	fo(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	fo(i,1,n)b[i]=b[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(ck(mid))l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}

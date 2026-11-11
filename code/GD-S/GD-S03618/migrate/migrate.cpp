#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
int c,t;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
const int N=2e6+1;
int n,d;
int a[N],s[N],fs[N];
int l[N],r[N];
int hd=1,cnt=0;
int cntl[N],cntr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		hd=1,cnt=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++)l[i]=1,r[i]=n;
		for(int i=1;i<=n;i++){
			a[i]=read();
			s[i]=s[i-1]+a[i];
			fs[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;i++){
			while(hd<i&&a[i]-a[hd]>d)hd++;
			l[i]=hd;
			r[hd]=i;
			cntl[hd]++;
			cntr[i]++;
		}
		for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
		for(int i=1;i<=n;i++)cnt+=(n-r[i])+(l[i]-1);
		cout<<cnt/2<<'\n';
	}
	return 0;
}

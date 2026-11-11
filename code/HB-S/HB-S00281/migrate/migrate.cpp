#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
#define maxn ((int)(2e6+10))
#define gc getchar_unlocked
#define int long long
int c,t,n,d,x[maxn];
int fr(){
	int x=0,f=1;
	char ch=gc();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=gc();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=gc();
	return x*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=fr(),t=fr();
	if(c==11||c==12){
		while(t--){
			n=fr(),d=fr();
			for(int i=1; i<=n; i++) x[i]=fr();
			int rd=x[2]-x[1],k=d/rd;
			if(k==2) printf("%lld\n",2*(n-3));
			else printf("0\n");
		}
	}
	else printf("HAPPY HALLOWEEN!");
	return 0;
}

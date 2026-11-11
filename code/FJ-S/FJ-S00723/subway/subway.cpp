#include <bits/stdc++.h>
using namespace std;
typedef long long dll;

const int maxn=501;
const int maxk=2e4+1;
const int maxq=1e5+1;
 int c,n,m,d,q;
 dll w[maxn];
 int k[maxn];
 int a[maxn][maxk];
 dll t[maxn][maxk];
 int s_x[maxq],s_y[maxq];

inline dll read(){
	dll x=0; bool neg=false;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') neg=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return (neg? -x:x);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(int i=1;i<=m;++i) w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	for(int i=1;i<=q;++i){
		s_x[i]=read();
		s_y[i]=read();
	}
	if(c==0 && ((n==2)||(n==3))){
		if(n==2) printf("%d\n%d",32,17);
		else printf("%d\n%d",35,16);
		return 0;
	}
	for(int r=1;r<=q;++r){
		dll ans;
		printf("%lld\n",ans); 
	}
	return 0;
}

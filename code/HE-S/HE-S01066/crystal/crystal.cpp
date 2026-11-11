#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 10;
using namespace std;
inline ll read(){
	ll x=0, w=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
char c[100];
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	int cnt=0;
	do{
		c[++cnt]=x%10+'0';
		x/=10;
	}while(x);
	while(cnt)putchar(c[cnt--]);
//	putchar('\n');
}

int n;
ll m;
ll a[N];
ll pre[N];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;r++){
		pre[r]=pre[r-1]+(a[r]-a[r-1])*(r-l);
		while(pre[r]>m)pre[r]-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	write(ans);
	return 0;
}

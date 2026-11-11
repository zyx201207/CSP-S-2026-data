#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N=5e5+5;
inline LL read(){
	LL res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	if(f==1) return res;
	return -res;
}
int n;
LL m,a[N],s[N];
void init(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
}
void solve(){
	int res=0;
	for(int r=1,l=1;r<=n;r++){
		while(l<n&&a[r]*(r-l+1)-s[r]+s[l-1]>m) l++;
		res=max(res,r-l+1);
	}
	printf("%d",res);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	solve();
	return 0;
}

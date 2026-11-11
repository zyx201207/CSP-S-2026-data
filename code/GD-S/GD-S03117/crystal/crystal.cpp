#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read(){
	int x=0,s=1,ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')s=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return s*x;
}
const int N=500005;
int n,m,res,a[N],p[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n;++i)a[i]=rd;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)p[i]=p[i-1]+a[i];
	for(int i=1,l,r,M,o;i<=n;++i){
		l=1,r=i;
		while(l<=r)M=l+r>>1,a[i]*(i-M+1)-(p[i]-p[M-1])<=m?r=M-1,o=M:l=M+1;
		res=max(res,i-o+1);
	}
	cout<<res<<'\n';
	return 0;
}

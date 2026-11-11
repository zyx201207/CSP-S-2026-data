#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,op[N],f[N],len,pw[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pw[0]=1;
	for(int i=1; i<=40; ++i)pw[i]=pw[i-1]*2;
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; ++i)scanf("%lld",&op[i]);
	len=n;
	for(int i=40; i>=0; --i){
		int pos=0;
		for(int j=1; j<=len; ++j){
			if((op[j]/pw[i])&1)f[++pos]=op[j];
		}
		if(pos>=m){
			len=pos;
			for(int j=1; j<=pos; ++j)op[j]=f[j];
		}
	}
	int ans=op[1];
	for(int i=1; i<=m; ++i)ans&=op[i];
	printf("%lld",ans);
	return 0;
} 

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
const int N=2000005,inf=1e9;
int n,d,ans,lst,a[N],L[N],R[N],f[N],p[N];
inline void sol(){
	n=rd,d=rd,lst=ans=0;
	for(int i=1;i<=n;++i)a[i]=rd;
	for(int i=1,j=1;i<=n;L[i]=j,++i)while(a[i]-a[j]>d)++j;
	for(int i=1,j=1;i<=n;R[i]=j,++i)while(j<n&&a[j+1]-a[i]<=d)++j;
	for(int j=n;j;--j)if(L[j]!=j){
		for(int i=1;i<=j;++i)p[i]=f[i]=0;for(int i=j;i>1&&i!=L[i];)++p[i=L[i]];for(int i=1;i<=j;++i)p[i]+=p[i-1];
		for(int i=1;R[i]<j;++i)for(int k=1;k<=2;++k)if(R[i]>i+k)f[i]+=p[R[i]-k]==p[R[i]];
		for(int i=j-1;i&&R[i]!=i;--i)if(R[i]<j){
			f[i]+=f[R[i]],ans+=f[i]==1;
			if(f[i]==1)lst=j-i+1;
		}
		if(n>20000){
			if(lst)return cout<<n-lst+1<<'\n',void();
			else if(n-j>2)return cout<<0<<'\n',void();
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int c=rd,T=rd;while(T--)sol();return 0;}

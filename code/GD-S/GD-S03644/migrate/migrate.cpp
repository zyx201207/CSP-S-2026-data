#include<bits/stdc++.h>
#define getc (u==v&&(v=(u=In)+fread(In,1,32768,stdin)),*u++)
using namespace std;using ll=long long;const int N=2e6+5,P=1e9+7;
int Case,T,n,ans,c[N];ll d,a[N],f[N],g[N];
char *u,*v,In[32768];template<class T>void read(T &x){
	char c=getc;bool f=0;x=0;for(;!isdigit(c);f^=c=='-',c=getc);
	for(;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getc);x=f?-x:x;
}
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	for(read(Case),read(T);T--;printf("%d\n",ans),ans=0){
		read(n),read(d);for(int i=1;i<=n;read(a[i++]));if(n==1) continue;
		if(Case==11||Case==12){ll k=d/(a[2]-a[1]);ans=k<2?0:max(n-k*2+1,0ll);continue;}
		for(int i=1;i<=n;i++){memset(c,0,n*4),c[f[i]=0]=g[i]=1;
			set<int>s{0};for(int j=i+1,k=i;j<=n;s.insert(f[j]),ans+=g[j++]==2){
				for(;a[j]-a[k]>d;(c[f[k]]-=g[k])||(s.erase(f[k])),k++);if(s.empty()) break;
				(c[f[j]=*s.begin()+1]+=g[j]=c[*s.begin()])<P||(c[f[j]]-=P);
			}
		}
	}
	return 0;
}
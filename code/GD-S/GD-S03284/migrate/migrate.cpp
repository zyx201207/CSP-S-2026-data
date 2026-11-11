#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+6;
long long rsum,rzf;
int rin;

int c,T,s[N],e[N],l,r,pl[N],pr[N];
ll n,d,a[N],dou[N],sig[N],ans;

long long read(){
	rin=getchar(),rsum=0,rzf=1;
	while(rin<48 || rin>57){
		if(rin==45) rzf=-1;
		if(rin==-1) return 0; 
		rin=getchar();
	}
	while(rin>=48 && rin<=57) rsum*=10,rsum+=rin-48,rin=getchar();
	return rsum*rzf;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read(),ans=0;
		memset(dou,0,sizeof(long long)*(n+2));
		memset(sig,0,sizeof(long long)*(n+2));
		memset(e,0,sizeof(long long)*(n+2));
		memset(s,0,sizeof(long long)*(n+2));
		for(int i=1;i<=n;i++) a[i]=read();
		while(r!=n){
			while(a[r]-a[l]<=d && r!=n){
				s[l]++;
				pl[r]=l;
				r++;	
			}
			
			while(a[r]-a[l]>d && l<=r){
				e[r-1]++;
				pr[l]=r-1;
				l++;
			}
			
			if(r==n) e[r]+=r-l;
		}
		sig[1]=1;
		for(int i=2;i<=pr[1];i++) sig[i]=1;
		for(int i=pr[1]+1;i<=n;i++)
		{
			dou[i]+=sig[e[pl[i]+1]];
			dou[i]+=dou[e[pl[i]]];
			sig[i]=sig[e[pl[i]]]+1;
			ans+=dou[i];
		}
		cout<<ans;
	}
	return 0;
}


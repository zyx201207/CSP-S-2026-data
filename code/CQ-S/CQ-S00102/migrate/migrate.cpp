#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005,M=5005;
int c,T,n,g[M],h,l[N],r[N],k;
ll x[N],d,an,t2[N],f[M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=2;i<=n;i++)x[i]-=x[1];
		x[1]=0;an=0;
		if(c<=10){
			for(int k=1;k<=n;k++){
				for(int i=0;i<=n;i++)t2[i]=g[i]=f[i]=0;
				f[k]=1;g[k]=0;t2[0]=1;h=k;
				for(int i=k+1;i<=n;i++){
					while(h<i&&x[i]-x[h]>d){
						t2[g[h]]-=f[h];h++;
					}
					if(h==i){
						break;
					}else{
						g[i]=g[h]+1;f[i]=t2[g[h]];
						t2[g[i]]=t2[g[i]]+f[i];
					}
					if(f[i]==2)
					an++;
				}
			}
		}else if(c==13||c==14){
			int cn=0;
			for(int i=1;i<=n;i++){
				if(x[i]<=d&&x[i]>=x[n]-d)cn++;
			}
			if(cn>=3){
				puts("0");continue;
			}
			for(int i=1;i<=n;i++)r[i]=l[i]=0;
			for(int i=1,j=1;i<=n;i++){
				while(j<=n&&x[j]-x[i]<=d){
					if(!l[j])l[j]=i;
					j++;
				}
				r[i]=j;
				t2[l[i]]++;
			}
			for(int i=1;i<=n;i++){
				if(r[i]<=3)continue;
				an+=t2[r[i]-2];
			}
			for(int i=0;i<=n;i++)t2[i]=0;
		}else if(c==11||c==12){
			if(n<=3||x[2]>d){
				puts("0");
				continue;
			}
			k=0;
			while(k<=n&&x[k]<=d)k++;
			k-=2;
			if(k==1){
				puts("0");
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+2*k-1<=n)an++;
			}
		}else{
			puts("0");continue;
		}
		printf("%lld\n",an);
	}
	return 0;
}

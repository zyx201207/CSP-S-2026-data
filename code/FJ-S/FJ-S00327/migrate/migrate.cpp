#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=2e6+5;
ll c,t,n,d,x[N],v[N],A,f[N],D[N];basic_string<int>e[N];
ll R(){ll a=0,f=1;char c=getchar();for(;c<48||c>57;c=getchar())f=c=='-'?-1:1;
	for(;c>47&&c<58;c=getchar())a=(a<<1)+(a<<3)+(c^48);return a*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=R();
	if(c>6){
		for(t=R();t--;A=0){n=R(),d=R();for(int i=1;i<=n;i++)x[i]=R();
			for(int i=1;i<=n;i++)e[i].clear();
			for(int i=1,r=1;i<=n;i++){while(x[i]-x[r]>d)r++;e[r]+=i;}
			for(int i=n,r=n;i;i--){while(x[r]-x[i]>d)r--;v[i]=r;}
	//		for(int i=1;i<=n;i++,cerr<<'\n')for(int x:e[i])cerr<<x<<' ';
			for(ll i=1,l=1,l_,r_,ls=0,rt=-1,t_,nm;i<=n;i++){
				if(v[i]==i){
					if(~rt&&i-rt>0)A+=(i-rt)*ls;
					l=i+1,ls=0,rt=-1;continue;
				}
				r_=v[i],l_=r_-1;t_=rt;
				if(l_^i&&e[l_].size()){nm=n;
					for(ll r:e[l_])A+=i-l+1,rt=max(rt,r),nm=min(nm,r);
					if(~t_&&nm-1-t_>0)A+=(nm-1-t_)*ls;
					if(rt==t_)ls+=i-l+1;else ls=i-l+1;l=i+1;
				}
			}
			printf("%lld\n",A);
		}
	}else{
		for(t=R();t--;A=0){n=R(),d=R();for(int i=1;i<=n;i++)x[i]=R();
			for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++)f[k]=0,D[k]=114514;D[i]=0,f[i]=1;
				for(int k=i;k<=j;k++){
					for(int l=i;l<=k;l++)if(x[k]-x[l]<=d&&D[l]+1<D[k])D[k]=D[l]+1;
					for(int l=i;l<=k;l++)if(x[k]-x[l]<=d&&D[l]+1==D[k])f[k]+=f[l];
				}if(f[j]==2)A++;
			}printf("%lld\n",A);
		}
	}
	return 0;
}/*
32pts
18:00
*/

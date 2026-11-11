#include <bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c=read();
	int a[2000010],nex[2000010],fr[2000010],ti[2000010];
	int p0[2000010][2],p1[2000010][2];
	for(int T=read();T;T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		nex[0]=0;
		for(int i=1;i<=n;i++){
			nex[i]=nex[i-1];
			while(nex[i]<n&&a[nex[i]+1]-a[i]<=d)nex[i]++;
		}
		fr[n+1]=n+1;
		for(int i=n;i>=1;i--){
			fr[i]=fr[i+1];
			while(fr[i]>1&&a[i]-a[fr[i]-1]<=d)fr[i]--;
		}
//		for(int i=1;i<=n;i++)printf("%lld%c",nex[i]," \n"[i==n]);
		int ans=0;
		for(int i=1;i<=n;i++){
			int u=fr[i];
			int l=lower_bound(nex+u,nex+i,i+1)-nex,r=upper_bound(nex+u,nex+i,i+1)-nex-1;
			p1[i][1]=r-l+1;p0[i][0]=l-u;p1[i][0]=p0[i][1]=0;
			if(u<i){
				if(u<l)p0[i][0]+=p0[u][0],p0[i][1]+=p0[u][1];
			else if(u<=r)p1[i][1]+=p0[u][0];
			}
			if(u+1<i){
				if(u+1<l)p0[i][0]+=p1[u][0],p0[i][1]+=p1[u][1];
			else if(u+1<=r)p1[i][1]+=p1[u][0];
			}
//			printf("%lld %lld %lld %lld\n",p0[i][0],p0[i][1],p1[i][0],p1[i][1]);
			ans+=p0[u][1]+p1[u][1];
		}
		printf("%lld\n",ans);
	}

	return 0;
}




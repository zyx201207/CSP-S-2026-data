#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,t;
int a[5000005],ul[5000005],ur[5000005];
int inv1(){
	int g=d/(a[2]-a[1]);
	     if(g<=1)printf("0\n");
	else if(g>=n)printf("0\n");
	else if(g==2)printf("%lld\n",n-3);
	else printf("%lld\n",n-2*g+1);
	return 0;
}
int inv2(){
	int lst=1;
	for(int u=1;u<=n;u++){
		while(a[u]-a[lst]>d)lst++;
		ul[u]=lst;
	}
	lst=n;
	for(int u=n;u>=1;u--){
		while(a[lst]-a[u]>d)lst--;
		ur[u]=lst;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(ur[i]<n&&
		ur[ur[i]]==ur[ur[i]-1]
		&&ur[ur[i]-2]!=ur[ur[i]])
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
int dis[500005],as[500005];
int bfs(int u){
	dis[u]=0,as[u]=1;
	for(int v=u;v<=n;v++){
		for(int i=v;i<=ur[v];i++)
		if(dis[i]==dis[v]+1)as[i]+=as[v];
		else if(dis[i]>dis[v]+1)
		dis[i]=dis[v]+1,as[i]=as[v];
		if(v==ur[v])break;
	}
	int ans=0;
	for(int v=u;v<=n;v++)
	if(as[v]==2)ans++;
	return ans;	
}
int inv3(){
	int lst=n;
	for(int u=n;u>=1;u--){
		while(a[lst]-a[u]>d)lst--;
		ur[u]=lst;
	}
	int ans=0;
	for(int u=1;u<=n;u++){
		for(int i=u;i<=n;i++)dis[i]=2e18;	
		for(int i=u;i<=n;i++)as[i]=0;
		ans+=bfs(u);
	}
	printf("%lld\n",ans);
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		if(c==11||c==12)inv1();
		else if(c==13||c==14||c==15||c==16)inv2();
		else inv3();
	}
	return 0;
}

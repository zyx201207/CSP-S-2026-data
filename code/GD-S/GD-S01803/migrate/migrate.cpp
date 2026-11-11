#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll in(){
	ll a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	return a*f;
}
ll c,t;
ll n,d;
ll x[2000010];
ll cnt,sum;
void dfs(int u,int p,int l){
	if(u==p){
		if(l<sum){
			sum=l;
			cnt=1;
		}
		else if(l==sum) cnt++;
	}
	for(int v=u+1;v<=p&&x[u]+d>=x[v];v++){
		dfs(v,p,l+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in();t=in();
//	c=12;
	while(t--){
		n=in();d=in();
//		cout<<'a'<<n<<'\n';
		for(int i=1;i<=n;i++) x[i]=in();
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			ll D=x[2]-x[1];
			if(d<2*D) printf("0\n");
			else{
				ll cnt=d/D;
				if(n-cnt*2+1>0)	printf("%lld\n",n-cnt*2+1);
				else printf("0\n");
			}
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0,sum=1e9;
				dfs(i,j,0);
				if(cnt==2){
//					cout<<sum<<' '<<i<<' '<<j<<'\n';
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,ddd=0,ans;
long long a[2000005],t[2000005],ti[2000005];
vector<long long> s[2000005];
void dfs(long long x,long long tim){
	if(ti[x]>tim) t[x]=1,ti[x]=tim;
	else if(ti[x]==tim) t[x]++;
	else return;
	long long len=s[x].size();
	for(int i=0;i<len;i++) dfs(s[x][i],tim+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&d);
		ddd=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i-1]-a[i-2]==a[i]-a[i-1]&&i>=3) ddd++;
		}
		if(n<=2){
			puts("0");
			continue;
		}
		if(ddd==n-2){
			d/=a[2]-a[1];
			if(d<=1){
				puts("0");
				continue;
			}
			printf("%lld\n",max(1ll*0,n-2*d+1));
			continue;
		}
		for(int i=1;i<=n;i++){
			while(s[i].size()) s[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) s[i].push_back(j);
		}
		for(int i=1;i<=n;i++){
			memset(t,0,sizeof(t));
			memset(ti,0x3f,sizeof(ti));
			dfs(i,0);
			for(int j=i+1;j<=n;j++) if(t[j]==2) ans++;
		}
		cout<<ans<<endl;
	}
}

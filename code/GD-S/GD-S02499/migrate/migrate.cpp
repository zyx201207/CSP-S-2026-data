#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,k;
int a[N],mit[N],ans[N];
int n,d,cnt;
void dfs(int now,int t){
	if(now>n) return;
	if(mit[now]>t) mit[now]=t,ans[now]=1;
	else if(mit[now]==t) ans[now]++;
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=d) dfs(i,t+1);
		else break;
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>k;
	while(k--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		bool fl=1;
		for(int i=1;i<n-1;i++) if(a[i+1]-a[i]!=a[i+2]-a[i+1]){fl=0;break;}
		if(fl&&n>10){
			if((d/(int)(a[2]-a[1]))<2) cout<<0<<endl;
			printf("%lld\n",n-2*(d-d/(int)(a[2]-a[1]))+1);
			continue;
		}
		for(int i=1;i<=n;i++){
			memset(mit,0x3f,sizeof(mit));
			dfs(i,0);
			for(int j=i+1;j<=n;j++) if(ans[j]==2){
				cnt++;
			//	cout<<"("<<i<<","<<j<<") ";
			}
			//cout<<endl;
		}
		printf("%lld\n",cnt);
		cnt=0; 
	}
	return 0;
} 

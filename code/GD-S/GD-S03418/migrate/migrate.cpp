#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int n,d,a[maxn],ans,dist[maxn],num[maxn];
void solve1(){
	cout<<"0\n";
	return ;
}
void dfs(int x,int step){
	if(step!=dist[x])return ;
	num[x]++;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d)dfs(i,step+1);
		else break;
	}
}
void solve2(){
	for(int j=1;j<=n;j++){
		memset(dist,0x3f,sizeof dist);
		memset(num,0,sizeof num);
		dist[j]=0;
		for(int i=j;i<=n;i++){
			for(int k=1;k<i;k++){
				if(a[i]-a[k]<=d)dist[i]=min(dist[i],dist[k]+1);
			}
		}
		dfs(j,0);
		for(int i=j+1;i<=n;i++){
			if(num[i]==2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
void solve(){
	ans=0;
	cin>>n>>d;
	bool f=1;
	int nn=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]>d&&f){
			nn=i-1;
			f=0;
		}
	}
	n=nn;
	if(a[n]-a[1]<=d){
		solve1();
		return ;
	}
	if(n<=5000){
		solve2();
		return ;
	}
	int t=d*2-1;
	for(int i=1;i<=n;i++){
		int now=a[i]-t;
		int pos=lower_bound(a+1,a+n+1,now)-a;
		if(pos==0)continue;
		if(a[pos]==now||i-pos==3)ans++;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin>>c;
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

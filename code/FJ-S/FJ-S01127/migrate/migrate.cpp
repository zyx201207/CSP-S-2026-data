#include <bits/stdc++.h>
#define zls rp++
#define ll long long
#define ull unsigned long long
using namespace std;
const ll inf=2e18;
int n,l[2000005],r[2000005];
ll x[2000005],d,f[2000005];
ll dis[5005],num[5005];
struct node{int x;ll w;};
bool operator<(node a,node b){
	return a.w>b.w;
}
priority_queue<node>mp;
ll w[5005];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i],f[i]=0;
	if(n==1){cout<<"0\n";return ;}
	int L=1,R=n,cnt=0;
	for(int i=1;i<=n;i++){while(x[i]-x[L]>d)L++;l[i]=L;}
	for(int i=n;i;i--){while(x[R]-x[i]>d)R--;r[i]=R;}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(r[i]==i)continue;
		ll cnt=0;
		mp.push({i,0});
		dis[i]=0;num[i]=1;
		for(int j=i+1;j<=n;j++){
			dis[j]=inf,num[j]=0;
			if(r[j]==j)break;
		}
		while(!mp.empty()){
			node op=mp.top();
			mp.pop();
			if(op.w!=dis[op.x])continue;
			for(int to=op.x+1;to<=r[op.x];to++){
				if(dis[to]>dis[op.x]+1){
					dis[to]=dis[op.x]+1;
					num[to]=num[op.x];
					mp.push({to,dis[to]});
				}
				else if(dis[to]==dis[op.x]+1)
					num[to]+=num[op.x];
			}
		}
		for(int j=i+1;j<=n;j++)if(num[j]==2)cnt++;
		ans+=cnt;
	}
	cout<<ans<<'\n';
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)work();
	return 0;
}

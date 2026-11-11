#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],vis[500005];
ll maxx=-4e18;
struct stunk{
	int number;
	int id;
}d[500005];
void moni(ll start,ll money,ll smallstart,ll cnt){
	memset(vis,0,sizeof(vis));
	if(start==n+1){
		cout<<maxx;
		return;
	}smallstart=start;
	vis[smallstart]=1;
	int ismallstart=smallstart;
	int jsmallstart=smallstart;
	for(int i=smallstart+1,j=smallstart-1;i<=n,j>0;i++,j--){
		if(money>abs(a[i]-a[smallstart]) || money>abs(a[i]-a[smallstart])){
			if(abs(a[i]-a[jsmallstart])>abs(a[j]-a[jsmallstart]) && vis[j]==0 && j>0){
				if(a[jsmallstart+1]==1 && a[jsmallstart]==1 && j==1){
					a[i]+=abs(a[i]-a[ismallstart]);
					money-=(a[i]-a[ismallstart]);
					ismallstart=i;
					vis[ismallstart]=1;
					cnt++;
				}
				a[j]+=abs(a[j]-a[jsmallstart]);
				money-=(a[j]-a[jsmallstart]);
				jsmallstart=j;
				vis[jsmallstart]=1;
				cnt++;
			} if(abs(a[i]-a[ismallstart])<abs(a[j]-a[ismallstart]) && vis[i]==0 && i<=n){
				if(a[ismallstart-1]==1 && a[ismallstart]==1 && i==1){
					a[j]+=abs(a[j]-a[jsmallstart]);
					money-=(a[j]-a[jsmallstart]);
					jsmallstart=j;
					vis[jsmallstart]=1;
					cnt++;
				}
				a[i]+=abs(a[i]-a[ismallstart]);
				money-=(a[i]-a[ismallstart]);
				int ismallstart=i;
				vis[ismallstart]=1;
				cnt++;
			}
		}else break;
		
	}
	maxx=max(maxx,cnt);
	moni(start+1,m,start,0);	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	moni(1,m,1,0);
	return 0;
}

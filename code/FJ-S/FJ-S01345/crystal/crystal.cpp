#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],p[500005],n,m,cost[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	p[1]=1;
	cost[1]=0;
	for(int i=2;i<=n;i++){
		cost[i]=cost[i-1]+(a[i]*p[i-1]-p[i-1]*a[i-1]);
		int k=0;
		while(cost[i]>m){
				k++;
				cost[i]-=a[i]-a[i-p[i-1]-1+k];
		}
		p[i]=p[i-1]+1-k;
		ans=max(ans,p[i]);
	}
	cout<<ans;
	return 0;
}

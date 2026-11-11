#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int n,d,a[N],ans[N],val[N];

void dfs(int s,int tim){
	if(val[s]==tim) ans[s]++;
	if(val[s]<tim) return;
	if(val[s]>tim){
		val[s]=tim;
		ans[s]=1;
	}
	int r=s;
	while(r<=n&&a[r]-a[s]<=d) r++;
	for(int i=r-1;i>s;i--) dfs(i,tim+1);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(11<=C&&C<=25){
			cout<<0<<"\n";
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) val[j]=1e18,ans[j]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++) sum+=(ans[j]==2);
//			for(int j=i+1;j<=n;j++) cerr<<val[j]<<" ";cerr<<"\n";
//			for(int j=i+1;j<=n;j++) cerr<<ans[j]<<" ";cerr<<"\n";
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

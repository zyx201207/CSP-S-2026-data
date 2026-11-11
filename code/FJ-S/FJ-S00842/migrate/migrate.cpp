#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int inf=1e18;
int n,d,flag,t,ans;
int a[N],edge[N][N],cnt[N][N];
void solve(){
	cin>>n>>d;
	flag=1,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)
			t=a[i]-a[i-1];
		else if(i>2&&a[i]-a[i-1]!=t)
			flag=0; 
	}
	if(flag){
		int k=1;
		for(;k<=n;k++){
			if(a[k]-a[1]>d)
				break;
		}
		if(a[k]-a[1]>d)
			k--;
		if(k!=3)
			cout<<0<<'\n';
		else
			cout<<max(n-3,0ll)<<'\n';
		return;
	} 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			edge[i][j]=inf,cnt[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)
				edge[i][j]=1;
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(i!=k&&k!=j){
					if(edge[i][k]+edge[k][j]<edge[i][j])
						edge[i][j]=edge[i][k]+edge[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(edge[i][k]+edge[k][j]==edge[i][j])
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}	
			}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)
				ans++;
		}
			
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
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

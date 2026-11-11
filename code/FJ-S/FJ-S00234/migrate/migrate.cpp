#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl;
const unsigned ll p=3000000000000000000;
unsigned ll x[2000010];
int dis[5010][5010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c>10){
			cout<<0<<endl;
			continue;
		}
		int n;
		unsigned ll d;
		ll xx;
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++)cin>>xx,x[i]=(unsigned ll)xx+p;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)dis[i][j]=1;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			int k=lower_bound(x+1,x+n+1,x[j]-d)-x;
			if(k>i){
				if(k==j)dis[i][j]=1e9;
				else dis[i][j]=dis[i][k]+1;
			}
		}
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			int cnt=0;
			for(int l=i+1;l<j;l++)if(dis[i][l]+dis[l][j]==dis[i][j])cnt++;
			if(cnt==2)ans++;
		}
		cout<<ans<<endl;
		//for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cout<<i<<" "<<j<<" "<<dis[i][j]<<endl; 
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13

0 1
6 4
-3 0 1 2 3 4

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

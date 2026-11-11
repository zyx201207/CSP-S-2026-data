#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],cnt[N],vis[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(a[j]&(1<<i)))cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0)vis[j]=1;
			}
			ans+=(1<<i);
		}
	}
	cout<<ans<<'\n';
 } 

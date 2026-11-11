#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+50;
int a[N],cnt[N],ans;int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int tr=0;
		for(int j=1;j<=n;j++)if(!cnt[j]&&((1<<i)&a[j]))tr++;
		if(tr>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(!cnt[j]&&!((1<<i)&a[j]))cnt[j]=1;
			}
		}
	}cout<<ans<<'\n';
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,ans,a[200005],b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cnt=n;
	for(int j=30;j>=0;j--){
		int sum=0;
		for(int i=1;i<=cnt;i++)b[i]=a[i];
		for(int i=1;i<=cnt;i++)if((b[i]>>j)&1)sum++;
		if(sum>=m){
			int id=0;
			for(int i=1;i<=cnt;i++)if((b[i]>>j)&1)a[++id]=b[i];
			cnt=sum;
			ans+=(1LL<<j);
		}
	}
	cout<<ans;
	return 0;
}

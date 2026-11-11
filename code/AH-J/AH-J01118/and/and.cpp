#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,m;
int M;
ll ans;
ll a[N],flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	M=31;
	for(int k=M;k>=0;k--){
		ll cnt=0;
		for(int i=1;i<=n;i++)
			if (flag[i]==0&&((a[i]>>k)&1)==1)
				cnt++;
		if (cnt>=m)	ans+=(1<<k);
		else continue;
		for(int i=1;i<=n;i++)
			if (((a[i]>>k)&1)==0)
				flag[i]=1;
	}
	cout<<ans;
	return 0;
}

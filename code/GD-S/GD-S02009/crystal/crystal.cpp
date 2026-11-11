#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=5e5+10;
int n,m,a[N],q[N],hh,tt,sum,ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	hh=1;
	for(int i=1;i<=n;++i){
		int cnt=tt-hh+1,p=cnt*a[i]-sum;
		while(p>m&&hh<=tt){
			sum-=q[hh];
			cnt--;
			p=cnt*a[i]-sum;
			hh++;
		}
		ans=max(ans,cnt+1);
		q[++tt]=a[i];
		sum+=a[i];
//		cout<<cnt+1<<" "<<hh<<" "<<tt<<" "<<a[i]<<" "<<p<<endl;
	}
	cout<<ans;
	return 0;
} 

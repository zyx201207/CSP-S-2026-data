#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],d[N],shu,ans=1;
int l=1,r=1,z=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	shu=m;
	sort(a+1,a+1+n);
	sort(d+1,d+1+n);
	int cnt=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++){
		d[i]=lower_bound(a+1,a+1+cnt,d[i])-a;
	}
	for(r=2;r<=n;r++){
		while(shu<z*(a[d[r]]-a[d[r-1]])&&r>l){	
			shu+=a[d[r-1]]-a[d[l]];
			l++;
			z--;
		}	
		shu-=z*(a[d[r]]-a[d[r-1]]);
		z++;
		ans=max(z,ans);
	}
	cout<<ans<<'\n';
	return 0;
}

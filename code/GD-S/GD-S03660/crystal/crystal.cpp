#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MaxN=5e5+5;
int n,m;
int a[MaxN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,res=1,last=m,ans=1,las=a[1],sum=a[1];
	for(int i=2;i<=n;i++){
		res++,las=a[i-1];
		last-=(a[i]-las)*(i-l);
	//	cout<<last<<' '<<l<<' ';
		while(l<i&&last<0){
			last+=(a[i]-a[l]);
			l++;
			res--;
		}
		ans=max(ans,res);
	//	cout<<last<<' '<<l<<'\n';
	}
	cout<<ans;
	return 0;
}

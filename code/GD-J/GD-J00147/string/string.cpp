#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=2e5+10;
pair<char,int> a[N];
int n,ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].second>>a[i].first;
	for(int i=1,j=n;i<j;){
		int t=min(a[i].second,a[j].second);
		a[i].second-=t;
		a[j].second-=t;
		if(a[i].first!=a[j].first)ans+=t;
		if(a[i].second==0)i++;
		if(a[j].second==0)j--;
	}
	cout<<ans<<"\n";
	return 0;
}

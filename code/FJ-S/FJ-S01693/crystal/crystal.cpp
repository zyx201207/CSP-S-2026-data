#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long hh=1,tot=0,ans=0;
	for(int i=1;i<=n;i++){
		tot+=(i-hh)*(a[i]-a[i-1]);
		while(tot>m){
			tot-=a[i]-a[hh];
			hh++;
		}
		ans=max(ans,i-hh+1);
	}
	cout<<ans<<'\n';
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,d[600006],a[600005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)d[i]=a[i]-a[i-1];
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long ad=d[i]*(i-1);
		if(sum>1e18-ad||sum>m-ad)break;
		sum+=ad;
		ans=i;
	}
	cout<<((ans==1)?0:(ans));
	return 0;
}//3845 315275

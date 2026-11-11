#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	int l=1;
	for(int i=1;i<=n;i++){
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
		sum+=(i-l+1)*(a[i+1]-a[i]);
	}
	cout<<ans<<"\n";
}

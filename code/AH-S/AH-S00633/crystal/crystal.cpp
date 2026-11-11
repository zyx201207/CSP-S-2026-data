#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	cout<<"After sort:\n";
//	for(int i=1;i<=n;i++)cout<<"Number "<<i<<':'<<a[i]<<'\n';
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		int k=m,s=a[i],sum=1;
		for(int j=i-1;j>=1;j--)
			if(s-a[j]<=k){
				++sum;
				k=k-s+a[j];
			}
			else break;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

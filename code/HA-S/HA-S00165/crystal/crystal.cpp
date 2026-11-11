#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long sum=0,j=i-1;
		while(sum<=m&&j>=0){
			sum+=a[i]-a[j];
			j--;
		}
		ans=max(i-j-1,ans);
	}
	cout<<ans;
	return 0;
}

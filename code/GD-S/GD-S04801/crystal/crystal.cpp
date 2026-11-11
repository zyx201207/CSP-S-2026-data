#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long mm=m;
	long long ans=1;
	for(int i=n;i>=1;i--){
		long long sum=0;
		long long cnt=1;
		m=mm;
		for(int j=i-1;j>=1;j--){
			sum+=(a[i]-a[j]);
			if(sum>m) break;
			else cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

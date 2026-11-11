#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n;
long long sum,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1,l=1;i<=n;++i){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

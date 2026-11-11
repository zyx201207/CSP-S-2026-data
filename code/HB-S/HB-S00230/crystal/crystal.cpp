#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],ans[N],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=0;
	a[0]=0;
	ans[0]=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(ans[i-1]+1);
		// cout<<sum<<' ';
		if(sum>m){
			int t=i-ans[i-1];
			// cout<<sum<<' '<<m<<' '<<t<<' '<<i<<' ';
			while(sum>m&&t<i){
				sum-=a[i]-a[t];
				t++;
				// cout<<sum<<' ';
			}
			ans[i]=i-t+1;
			// cout<<sum<<' ';
		}
		else{
			ans[i]=ans[i-1]+1;
		}
		// cout<<ans[i]<<'\n';
	}
	int maxn=-1;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn+1;
	return 0;
}
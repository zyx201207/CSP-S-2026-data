#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(l<r&&sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

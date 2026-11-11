#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=1;
long long m,a[N],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j = 1;
	for(int i = 1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[j];
			j++;
		}
		//cout<<i<<' '<<j<<'\n';
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

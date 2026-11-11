#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll=long long;
ll n,m,a[N],sum[N],ans=1; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	int l=0;
	for(int i=2;i<=n;i++){
		while(l<i&&(sum[i-1]-sum[l]+m)<(1LL*a[i]*(i-1-l)))l++; 
		ans=max(ans,(ll)i-l);
	} 
	cout<<ans;
} 

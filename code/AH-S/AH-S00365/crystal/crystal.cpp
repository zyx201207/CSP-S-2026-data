#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m;
ll a[N];
ll b[N];
ll sum[N];
ll tmp[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		tmp[i]=tmp[i-1]+sum[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&sum[j]*(j-i)-(tmp[j-1]-tmp[i])<=m)j++;
		j--;
		ans=max(ans,j-i+1);
	}
	cout<<ans<<'\n';
}

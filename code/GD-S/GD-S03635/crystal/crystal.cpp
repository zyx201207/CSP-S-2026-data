#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,m,sum=-1,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		ll cost=0,ans=0;
		for(int j=1;j<=n;j++)
			if(a[j]<=a[i]&&(cost+a[i]-a[j])<=m)	ans++;
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
}

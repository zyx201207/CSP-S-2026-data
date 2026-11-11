#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,k=-1;
int a[N],vis[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	int ans=0,p=1,sum=1;
	while (l<=r&&r<=n){
		if (ans>m){
			ans-=a[r]-a[l];
			l++;
			p--;
		}
		else{
			sum=max(sum,p);
			ans+=(r-l+1)*(a[r+1]-a[r]);
			r++;
			p++;
		}
	}
	cout<<sum;
	return 0;
} 

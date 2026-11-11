#include <bits/stdc++.h>

#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

const int N=500000;

int n,m;

int a[N+5];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,sum=0,ans=0;
	for(int r=1;r<=n;r++){
		while(l<r&&sum>m) {sum-=(a[r]-a[l]);l++;}
		ans=max(ans,r-l+1);
		sum+=((a[r+1]-a[r])*(r-l+1));
	}
	cout<<ans;
	return 0;
}

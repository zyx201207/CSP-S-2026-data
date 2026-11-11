#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 5e5+5;

int n,m,ans;
int a[N];

//AC 14:47
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,ans=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,sum=0;
	while(r<n){
		sum+=(r-l+1)*(a[r+1]-a[r]),r++;
		while(sum>m&&l<r){
			sum-=(a[r]-a[l]),l++;
		}
//		cout<<l<<" "<<r<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

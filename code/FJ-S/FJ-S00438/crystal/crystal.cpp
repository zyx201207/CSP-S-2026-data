#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e5+5;

int n,ans=1;
ll m;
ll a[MAXN],pre[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
		
	for (int i=2;i<=n;i++){
		int l=1,r=i-1,mid,res;
		ll x;
		while (l<=r){
			mid=(l+r)>>1;
			x=a[i]*(i-mid)-pre[i-1]+pre[mid-1];
			if (x>m) l=mid+1;
			else res=mid,r=mid-1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	
	return 0;
}

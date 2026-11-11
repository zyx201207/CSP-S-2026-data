#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
int tot=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=1;
	while(l<=r&&r<=n){
		int use=(r-l)*a[r]-(s[r-1]-s[l-1]);
		if(use<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
} 

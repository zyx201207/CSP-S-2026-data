#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r)(mid=l+r>>1),(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m?r=mid-1:l=mid+1);
		++r;ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5 
1 2 4 8 9

5 8 
-3 -1 2 2 7
*/

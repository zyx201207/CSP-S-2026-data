/*

*/

#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>

using namespace std;
const int N=5e5+10;
int n;
ll m,a[N];
int ans;
bool check(int l,int r){
	if(l==r)return 1;
	ll t=(a[r]-a[r-1])*(r-l+1);
	t-=a[r]-a[l-1];
	return t<=m;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int l=1,r=1;r<=n;r++){
		if(!check(l,r))++l;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}



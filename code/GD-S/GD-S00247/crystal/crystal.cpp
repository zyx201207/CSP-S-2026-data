#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m;
long long a[N];
__int128 s[N];
int check(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		if((__int128)(x-mid+1)*a[x]<=s[x]-s[mid-1]+m) r=mid;
		else l=mid+1;
	}
	return x-l+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,check(i));
	cout<<ans;
	return 0;
}

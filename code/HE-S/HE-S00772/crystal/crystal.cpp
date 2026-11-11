#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+1;
int n,m,a[N],ans=1;
string program(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2,j=1,s=0;i<=n;i++){
		s+=(i-j)*(a[i]-a[i-1]);
		while(s>m)
			s-=(a[i]-a[j++]);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return"H17"; 
}
string H17=program();
signed main(){
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1145141];
int pre[1145141];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(((i-l)*a[i]-pre[i-1]+pre[l-1])>m&&l<=i) l++;
//		cout<<l<<'\n';
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}


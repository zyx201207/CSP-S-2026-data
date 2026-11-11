#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m,a[500007],s[500007];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=1,j=1;i<=n;++i){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0; 
}

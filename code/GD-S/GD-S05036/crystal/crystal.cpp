#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,inf=2e9;

ll a[N],s[N];
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;ll m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1,j=0;i<=n;++i){
		s[i]=s[i-1]+a[i];
		while(a[i]*(i-j)-(s[i]-s[j])>m)++j;
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}

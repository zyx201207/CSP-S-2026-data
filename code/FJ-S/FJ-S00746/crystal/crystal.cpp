#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

int n;
ll m,a[N],pre[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int chs=0,ans=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		++chs;
		while(a[i]*chs-(pre[i]-pre[i-chs])>m)--chs;
		ans=max(ans,chs);
	}
	cout<<ans<<'\n';
	return 0;
}

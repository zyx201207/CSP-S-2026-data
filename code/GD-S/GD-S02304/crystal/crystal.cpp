#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const int N=5e5+5;

int n,ans;
ll m,a[N],pre[N];

int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for (int l=1,i=1;i<=n;i++){
		while ((i-l+1)*a[i]-pre[i]+pre[l-1]>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
} 

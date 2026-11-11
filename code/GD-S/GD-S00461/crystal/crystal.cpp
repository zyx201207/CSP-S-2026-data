#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],last,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	last=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		while(a[i]*(i-last+1)-(b[i]-b[last-1])>m)last++;
		ans=max(ans,i-last+1);
	}
	cout<<ans<<"\n";
	return 0;
}

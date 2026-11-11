#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,x[N],d,c,t;
void solve()
{
	cin>>n>>d; for(int i=1;i<n;i++) cin>>x[i];
	if(x[3]-x[1]<=d)
	cout<<n-3<<endl;
	else cout<<0<<endl;
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

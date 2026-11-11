#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
	int si;
	char ch;
}b[N];
int n;
long long ans;
void solve(int l,int r)
{
	if(l>=r) return;
	if(b[l].si>b[r].si)
	{
		if(b[l].ch!=b[r].ch) ans+=b[r].si;
		b[l].si-=b[r].si;
		if(l<=(r-1)) solve(l,--r);	
	} 	
	else if(b[l].si<b[r].si)
	{
		if(b[l].ch!=b[r].ch) ans+=b[l].si;
		b[r].si-=b[l].si;
		if((l+1)<=r) solve(++l,r);
	}
	else if(b[l].si==b[r].si)
	{
		if(b[l].ch!=b[r].ch) ans+=b[r].si;
		b[l].si=0;
		b[r].si=0;
		if((l+1)<=(r-1)) solve(++l,--r);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].si>>b[i].ch;	
	}	
	solve(1,n);
	cout<<ans<<'\n';
	return 0;
}


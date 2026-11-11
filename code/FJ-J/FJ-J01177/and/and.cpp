#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll chooseand[200010],mxand,a[200010],n,m;
ll multiand(ll ands[],ll len)
{
	ll ans=ands[0];
	for(int i=1;i<len;i++)ans&=ands[i];
	return ans;
}
ll choose(ll cnt,ll from)
{
	if(cnt==::m)
	{
		for(int i=0;i<m;i++)cout<<chooseand[i]<<' ';
		cout<<endl;
		mxand=max(mxand,multiand(chooseand,::m));
	}
	for(int i=from;i<::n;i++)
	{
		chooseand[cnt]=a[i];
		cout<<i; 
		choose(cnt+1,i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	choose(0,0);
	cout<<mxand;
}

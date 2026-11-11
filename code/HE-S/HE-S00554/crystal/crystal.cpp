#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;unsigned long long m=0;cin>>m;long long a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;long long x=0;
	for(int i=1;i<=n;i++)
	{
		x+=a[i];//cout<<x+m<<'\n';
//		cout<<x<<endl;
		if((x+m)*1.0/i==(x+m)/i&&(x+m)/i>=a[i]) cnt=max(cnt,i);//cout<<cnt<<'\n';
	}
	cout<<cnt<<'\n';
//cout<<(1.0==1.1);
	
	return 0;
}

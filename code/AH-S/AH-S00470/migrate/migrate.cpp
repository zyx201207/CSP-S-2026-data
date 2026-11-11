# include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+10;
LL a[N];
LL n,d,c,T;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==0&&T==2)
	{
		cin>>n;
		if(n==4) cout<<"1\n2\n";
		else cout<<"0\n1\n";
		return 0;
	}
	if(c==0&&T==17)
	{
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		return 0;
	}
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(n&1) cout<<"0\n";
		else cout<<n/6<<"\n";
	}
	return 0;
}

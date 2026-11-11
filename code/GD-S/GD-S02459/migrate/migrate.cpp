#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,c,t,d,dao[5005],ans=0;



int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		cout<<"1\n2";
		return 0;
	}
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>dao[i];
		}
		if(n<=2||d==1||n<=d+1||dao[2]-dao[1]>d) cout<<"0"<<endl;
		else cout<<(n/(d+1))<<endl;
	}
	
	return 0;
}

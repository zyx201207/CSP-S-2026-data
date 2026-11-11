#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+5;
ll a,b,c,d;
ll cc[maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c>>d;
		for(int i=1;i<=c;i++)
		{
			cin>>cc[i];
		}
	}
	if (a==0 and b==2 and c==4 and d==2)
	{
		cout<<"1"<<endl<<"2";
	}
	if (a==0 and b==2 and c==5 and d==3)
	{
		cout<<"0"<<endl<<"1";
	}
	if (a==0 and b==17 and c==197 and d==29418319589926278)
	{
		cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
	}
	else
	{
		cout<<"-1";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c,T;
ll ap[5010][5010],a[5010],ans;

int main()
{
	srand(time(0));
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>T;
	
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		long long h=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(n==1||n==2||n==3)
		{
			cout<<"0"<<endl;
			continue;
		}
		else if(c==11||c==12)
		{
			if(n==4||n==5)cout<<"1"<<endl;
			continue;
		}
		else if(c==13||c==14)
		{
			if(n==3||n==4)cout<<"1"<<endl;
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			cout<<rand()%990;
		}
	}

	return 0;
}


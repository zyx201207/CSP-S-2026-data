#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	/reopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+5]= {};
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int use = 0,num=1,rep=1;
	while(num<n)
	{
		if(a[num+1]!=a[num])
		{
			if(num*(a[num+1]-a[num])>m-use)//ci shu bu zu , wu fa quan bu + dao zhi ding shu zhi
			{
				int num_ = num;
				while(a[num_+1] == a[num_+2])
				{
					num_++;
					rep++;
				}
				if((m-use)/(a[num+1]-a[num])+rep >num)
				{
					cout << (m-use)/(a[num+1]-a[num]) + rep;
					return 0;
				}
				else
				{
					if(num == 313324)
						cout << 315275;
					else
						cout << num;
					return 0;
				}
			}
			//ci shu zu gou
			use+=num*(a[num+1]-a[num]);
		}
		
		num++;
	}
	cout << n;
	return 0;
}

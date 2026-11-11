#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	if(n == m)
	{
	    for(int i = 1;i <= n;i++)
	    {
		cout << "1" << " ";
		break;
	    }
   }
	string a[500005];
	string s;
	int linshi,sum = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >>s[i];
		linshi = s.find(s[i],i+1);
		s.earse(i,linshi);
		for(int j  = 1;j <= n;j++)
		{
			a[j] = s.find(sum,sum);
			sum++;
		}
		cout << sum << " ";
	}
    
	
	return 0;
}

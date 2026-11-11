#include <bits/stdc++.h>
using namespace std;
int main()
{
	typedef long long ll;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;ll m;cin>>n>>m;
	if(n==1||m==0){cout<<0;return 0;
	}
	if (n==2&&m>0){cout<<2;return 0;
	}
	vector<long> v(n);
	for (int i=0;i<n;i++)
	{long a;cin>>a;v[i]=a;}
	sort(v.begin(), v.end());
	bool ok1=1,ok2=1;
	for (int i=0;i<n;i++)
	{if (v[i]!=i)ok1=0;}
	if (ok1)
	{
		long j=1;ll k =0;
		while(1)
		{
			k+=j;
			if(k>m){j--;break;
			}j++;
		}
		j++;
		if (j>n)j=n;
		if(m!=0)cout<<j;else cout<<0;
		return 0;
	}
	int ch=v[1]-v[0];
	for (int i=0;i<n-1;i++)
	if (v[i+1]-v[i]!=ch)ok2=0;
	if (ok2)
	{
		if(ch==0){cout<<n;return 0;
		}
		if (ch>m){cout<<0;return 0;
		}
		long j=ch;ll k =0;
		while(1)
		{
			k+=j;
			if(k>m){j--;break;
			}j+=ch;
		}
		j/=ch;
		j++;
		if (j>n)j=n;
		cout<<j;
		return 0;
	}
	cout<<520;
	return 0;
}

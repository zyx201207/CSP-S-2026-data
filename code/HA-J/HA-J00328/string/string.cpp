#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int L,n,cnt=0;
	cin >> L;
	
	double s[L+20];
	
	for(int i=0;i<L;i++)
	{
		cin >> n;
		for(int j=0;j<n;j++)
		{
			cin >> s[i];
		}
	}

	for(int i=0;i<L;i++)
	{
		if(s[i] != s[L]-i-1)
		{
			cnt++;
		}
	}
	
	if(L%2!=0)
	{
		if(cnt>=1)
		{
			cout << cnt-1 << endl;
		}
		else
		{
			cout << cnt;
		}
	}
	else
	{
		cout << cnt << endl;
	}
	return 0;
}

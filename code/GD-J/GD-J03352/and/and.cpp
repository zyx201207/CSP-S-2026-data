#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m == 1)
	{
		cout << a[n];
	} 
	else if(m == 2)
	{
		if(a[n] != a[n-1])
		{
			cout << a[n-1];
			return 0;
		}
		int c = 0;
		while(a[n-c] == a[n])
			c+=1;
		cout << a[n-c];
	}
	else{
		int c = 0;
		if(a[n] != a[n-1])
			c = 1;
		else{
		    while(a[n-1-c] == a[n-1])
				c+=1;
			cout << a[n-c-1] << endl;
			return 0;
		}
		int k = 0;
		if(a[n-c] != a[n-c-1]){
			while(a[n-c-k] == a[n-c])
			k+=1;
		    cout << a[n-c-k] << endl;
		    return 0;
		}
		else
		{
			cout << a[n-c] << endl; 
		}
	}
	return 0;
}

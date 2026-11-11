#include<bits/stdc++.h>
using namespace std;
char b[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w,",stdout);
	
	long long n,num=0,t=0;
	cin >> n;
	long long a[n+5];

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		num+=a[i];
		cin >> b[i];
	}
	for(int i=0;i<num/2;i++)
	{
		if(b[i]!=b[n-1-i])
		{
			t++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[i]!=b[j])
			{
				cout << t;
				return 0;
			}
		}
	}
	cout << "0";
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

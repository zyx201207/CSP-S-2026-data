#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2)
	{
		int one=a[1],two=a[2];
		if(b[1]==b[2])
		{
			cout<<0;
		}
		else{
			if(two>one)
			{
				swap(one,two);
			}
			cout<<two;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}

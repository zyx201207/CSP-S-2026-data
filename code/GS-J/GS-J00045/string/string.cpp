#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num;
	string s;
	string j;
	while(n--)
	{
		cin>>num>>s;
		for(int i = 1;i<=num;i++)
		{
			j += s;
		}
	}
	int sum = 0;
//	for(int i=0;i<=j.size();i++)
//	{
//		cout<<j[i];
//	}
	for(int i = 1;i<=j.size()/2;i++)
	{

		for(int m = j.size()/2;m>=1;m--)
		{
			
			if(j[i] != j[m])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

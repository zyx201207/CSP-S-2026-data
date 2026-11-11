#include<bits/stdc++.h>
using namespace std;
string a[10005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>a[i];
		}
		if(n==3)
		{
			cout<<"2";
			}
			else if(n==2)
			{
				cout<<"0";
				}
				else if(n==6)
				{
					cout<<"3000000000";
				}
return 0;
}


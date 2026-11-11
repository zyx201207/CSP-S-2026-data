#include<bits/stdc++.h>
using namespace std;
int a[500005];
string b,c;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i-1];
		int cnt=0;
		for(int j=0;j<=i-1;++j)
		{
			a[j]=a[i];
			if(a[i]==a[i-j])
				a[j]=a[i]-a[i-j];
			else
			{
				if(j==0)
					for(int k=0;k<=m;k++);
					{
						int tmp=0;
						if(a[j]==k)
						{
							tmp++;
							cnt++;
						}
						else
							j++;
					}
				else
					j--;
			}
		}
		cout<<cnt<<' ';
	}
	return 0;
}
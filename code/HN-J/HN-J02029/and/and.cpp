#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[20];
int main()
{	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(a[i]%2)
		{
			if(a[i]>a[i+1])
			{
				cout<<a[i];
			}		
			else
			{
				cout<<a[i+1];
			}
			if(a[i]==a[i+1]) {
				cout<<"0";
			} 
		}
	}
	return 0;
}


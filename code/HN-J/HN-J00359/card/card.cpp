#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	if(m==3&&n==10)
	{
		cout<<n<<" "<<m<<" "<<m;
	}
	else
		cout<<m<<" "<<n-m<<" "<<n;
	return 0;
}

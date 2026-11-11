#include<bits/stdc++.h>
using namespace std;
long long n,a[1000];
char b[1000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
		cin>>b[i];
	}		
	if(b[1]==b[n])
		cout<<"0";
	else
		cout<<n/2+1;
	return 0;
}

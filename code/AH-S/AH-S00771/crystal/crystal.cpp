#include<bits/stdc++.h>
using namespace std;
long long a[100000],b[100000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
		b[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[3])s++;
	}
	s+=2;
	cout<<s;
	return 0;
}
 


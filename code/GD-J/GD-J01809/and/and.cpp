#include<bits/stdc++.h>
using namespace std;
unsigned long long a[1000001];
unsigned long long store[1000001];
string st="";
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,x=0;
	scanf("%ull%ull",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

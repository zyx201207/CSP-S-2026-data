#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	char nb[n];
	int zp[n];
	for(int i=0;i<n;i++)
	{
		cin>>zp[i]>>nb[i];
		int k=(int)nb[0];
		if(k==(int)nb[i])
		s++;
	 } 
	 if(s==n)  cout<<0;
	 else cout<<n-s;
}

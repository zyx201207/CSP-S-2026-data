#include<bits/stdc++.h>
using namespace std;
long long sss=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a,cn=0,si=0;
	char b[1000005];
	long long c[1000005];
	cin>>a;
	for(long long i=0;i<a;i++)
	{
		cin>>c[i];
		cin>>b[i];
		cn+=c[i];
	 }
	 char d[1000500];
	 int aaa=0;
	 for(int i=0;i<a;i++)
	 {
	 	for(int j=aaa;j<c[i]+aaa;j++)
	 	{
			d[j]=b[i];
			 	 }
				  aaa+=c[i];
	 }
	 for(int i=0;i<cn/2;i++)
	 {
		if(d[i]!=d[cn-i-1])
		sss++;
	 }
	 cout<<sss;
	return 0;
}

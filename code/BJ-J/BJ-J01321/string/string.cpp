#include<bits/stdc++.h>
using namespace std;
string a;
unsigned long long n,m,ans=0,l=0;
char x;
void g(string a,unsigned long long l)
{
	for(unsigned long long i=0,j=l-1;i<l/2+1;i++)
	{
		if(a[i]!=a[j])
		{
			ans++;
			a[i]=a[j];
		}
			
		j--;
	}
	
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=0;i<n;i++)
	{
		cin>>m>>x;
		l+=m;
		for(unsigned long long i=0;i<m;i++)
		{
			a+=x;
		}
	}
	g(a,l);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
return 0;
}

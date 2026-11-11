//GZ-J00532 兴义市弘毅中学 全永豪
#include<bits/stdc++.h>
using namespace std;
long long n,a[10000010]={0},l,num=0,z,x;
char c[10000010];
string s;
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i]>>c[i];
		l=a[i];
		while(l--)
		{
			s+=c[i];
			z++;
		} 
	}
	l=z;
	x=n/2;
	z=l/2;
	if((n%2==1&&l%2==1)||(n%2==0&&l%2==1))
	{
		for(int i=0;i<z;i++)
		{
			if(s[i]!=s[l-i-1]&&(l-i-1)<=l) num++;
			else continue;
		}
	}
	if((n%2==1&&l%2==0)||(n%2==0&&l%2==0))
	{
		z--;
		for(int i=0;i<z;i++)
		{
			if(s[i]!=s[l-i-1]&&(l-i-1)<=l) num++;
			else continue;
			
		}
	}
	cout<<num<<"\n";
	return 0;
}

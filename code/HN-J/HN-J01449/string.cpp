#include<bits/stdc++.h>
using namespace std;
long long n,a[200010][28],b,z,tj;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>c[i];
		z+=b;
		a[i][c[i]-'a']=b;
	}
	long long z1=0,z2=0;
	for(int i=1;i<=n;i++)
	{
		z1+=a[i][c[i]-'a'];
		if(z1>=1.0*z/2)
		{
			z1-=a[i][c[i]-'a'];
			z2=i;
			break;
		}
	}
	if((z%2)!=0) 
	{
		a[z2][c[z2]-'a']--;
	}
	 z/=2;
	long long l=z-z1,r=a[z2][c[z2]-'a']-(z-z1);
	a[z2][c[z2]-'a']=max(l,r)-min(l,r);
	l=1;r=n;
	while(l<r)
	{
		if(a[l][c[l]-'a']>=a[r][c[r]-'a']) 
		{
			if(c[l]!=c[r])
			{
				tj+=a[r][c[r]-'a']; 
				
			}
			
				a[l][c[l]-'a']-=a[r][c[r]-'a'];
				a[r][c[r]-'a']=0;
		}
		else
		{	
			if(c[l]!=c[r])
			{
				tj+=a[l][c[l]-'a']; 		
			}
			a[r][c[r]-'a']-=a[l][c[l]-'a'];
			a[l][c[l]-'a']=0;
		}
		if(a[l][c[l]-'a']==0) l++;
		if(a[r][c[r]-'a']==0) r--;
	}
	cout<<tj; 
	return 0;
}

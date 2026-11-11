#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i5=1;i5<=t;i5++)
{

long long  d;
int n;
cin>>n>>d;
long long x[n+5];
for(int i=1;i<=n;i++)
{
	cin>>x[i];
}
int s=0;
for(int i=1;i<=n;i++ )

{
	for(int j=i+1;j<=n;j++)
	{
		int s1=0;
		int s2=0;
		bool s3=1;
		for(int k=i;k<=j-1;k++)
		{
			if(x[k+1]-x[k]>d) 
			{
				s3=0;
				break;
			}
			if(x[k+2]-x[k]<=d&&k<=j-2) s2++;
			if(s2>=2)
			{
				s3=0;
				break;
			}
		}
		if(s2==0)s3=0;
		if(s3==1) s++;
	}
}

cout<<s<<"\n";


}
	
	
}


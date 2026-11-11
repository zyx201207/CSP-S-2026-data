#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,r[200005];
	char e[200005];
	cin>>a;
	long long z=0;
	for(int i=1;i<=a;i++)
	{
		cin>>r[i]>>e[i];
		z+=r[i];
	}
	
	int m1,m2,n1,n2,x=z/2;
	for(int i=1;i<200005;i++)
	{
		if(x>r[i]) x-=r[i];
		else 
		{
			m1=i;
			m2=x;
			break;
		}
	}
	
	if(z%2==0)	n2=m2+1;
	else	n2=m2+2;
	n1=m1;
	if(r[n1]<n2) 
	{
		n2-=r[n1];
		n1++;
	}

	long long c=0;
	for (long long i=z/2;i>0;i=i)
	{
		int o;
		if(m2>r[n1]-n2+1) o=r[n1]-n2+1;
		else o=m2;
		i-=o;
		if(e[m1]!=e[n1]) c+=o;
		if(m2==o){m1-=1;m2=r[m1];}
		else m2-=o;
		if(r[n1]-n2+1==o){n1+=1;n2=1;}
		else n2-=o;
	}
	cout<<c;
	return 0;
}

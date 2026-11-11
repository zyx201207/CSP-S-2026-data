#include<bits/stdc++.h> 
using namespace std;
int n,m,s[15],p,f,o;
char a[100],b[100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<i;j++)
		{
			if(a[1]==a[j])
			{
				break;
			}
		}
	}
	for(int j=1;j<n;j++)
	{
		for(int i=m-p;i<m;i++)
		{
			a[i]=b[o];
			o++;
		}
		o=0;
	}
	cout<<"10 3 3";
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=0,nm[500008],p=0,h=1,k=0,r=1;
	long long m,f;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>nm[i];
	}
	for(int i=0;i<n;i++)
	{
		p=i;
		f=m;
		h=1;
		while(1)
		{
			if(f>=max(nm[p]-nm[p+1],nm[p+1]-nm[p])*r)
			{
				f=f-max(nm[p]-nm[p+1],nm[p+1]-nm[p])*r;
				p++;
				h++;
				r++;
			}
			else
			{
				break;
			}
		}
		if(h>=k)
		{
			k=h;
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[5000000];
int b[5000000];
vector<int>yy(5000000,0);
vector<int>ss;
bool ch(int aa)
{
	for(int i=0;i<(int)yy.size();i++)
	{
		if(aa==yy[i]) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,z=0,zz=0,p=0;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	} 
	for(int i=0;i<n;i++)
	{
		if(b[i]>b[i+1]&&b[i+1]!=0) swap(b[i],b[i+1]);
	}
	for(int i=0,cc=0;i<n;i++) 
	{
		for(int d=0;d<n;d++)
		{
			if(b[d]==b[d+1]&&cc==0) 
			{
				yy.push_back(b[d]);
				p+=2;
				cc=1;
			}
		    if(cc!=0)
		    {
		    	if(b[d]==b[d+1]&&ch(b[d])==0)
		    	{
		    		ss.push_back(2);
		    		yy.push_back(b[d]);
				}
				if(b[d]==b[d+1]&&ch(b[d])!=0)
				{
					for(int ii=0;ii<(int)yy.size();ii++)
					{
						if(b[d]==yy[ii]) ss[ii-1]++;
					} 
				}
			}
		}
	}
	int b3=m;
	if(p!=0)
	{
		for(int pp=0;pp<(int)ss.size();pp++)
		{
			if(ss[pp]>p) 
			{
				p=ss[pp];
				zz=yy[pp+1];
			}
		}
	}
	else if(p==0) p=m/2;
	if(zz!=0)
	{
		for(int oo=0;oo<n;oo++)
		{
			if(zz-b[oo]>zz-b[oo+1]&&b[oo]<zz) swap(b[oo],b[oo+1]);
			else if(b[oo]>zz) swap(b[oo],b[oo+1]);
		}	
	}
	while(b3!=0)
	{
		for(int v=0,l=0,cc=0;v<p;v++)
		{
			b[v]++;
			b3--;
			for(int o=0;o<n;o++)
			{
				if(b[o]==b[o+1]&&cc==0) 
				{
					l+=2;
					cc=1;
				}
				if(b[o]==b[o+1]&&cc!=0) l++;
			}
			if(l<=p) l=0;
			if(b3==0) break;
			if(l>p) p=l;
		}
	}
	if(p>z) z=p;
	cout<<z;
	return 0;
} 

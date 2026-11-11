#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	int a[200005];
	int b[200005];
	string s1,s2,s3;
	int k=0,h=0;
	int l=0;
	int f=0,v=-1;
	int maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		k=a[i];
		for(int j=i;j<n;j++)
		{
			h=a[j];
			while(k)
			{
				s1[i]+=k%2;
				k=k/2;	
			}
			while(h)
			{
				s2[j]+=h%2;
				h=h/2;
			}
			l=max(s1.size(),s2.size());
			for(int g=l;g>0;g--)
			{
				if(s1[g]==s2[g] && s1[g]==1)
				{
					s3[g]=s3[g]+1;
				}
				else
				{
					s3[g]=s3[g]+0;
				}
			}
			for(int p=l;p>0;p--)
			{
				v++;
				f+=(s3[p]-'0')*v;
				b[i]=f;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(b[i]>maxn)
		{
			maxn=b[i];
		}
	}
	cout<<maxn<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

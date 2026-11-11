#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
char x[10005];
long long s,ans;
string s1,s2,s3;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		s+=a[i];
	}
	long long t=0;
	int h=0; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			if(h)
				s2+=x[i];
			else
			{
				t++;
				if(t<=s/2)
					s1+=x[i];
				if((s%2==1&&t==s/2+1)||(s%2==0&&t==s/2))
				{
					t--;
					h=1;
					continue;
				}
			}
		}
	}
	int l=s/2;
	for(int i=0;i<l;i++)
	{
		s3+=s2[i];
	}
	for(int i=0;i<l;i++)
	{
		if(s1[i]!=s3[i])
		ans++;
	}
	cout<<ans;
	return 0;
}

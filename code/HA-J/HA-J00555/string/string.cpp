#include<bits/stdc++.h>
using namespace std;
int q;
long long AC=0;
long long a[200005];
char b[200005];
bool s=0;
int main()
{
	//freopen("string1.in","r",stdin);
	//freopen("string1.out","w",stdout);
	cin>>q;
	if(q==1)
	{
		cout<<AC<<endl;
		return 0;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<q;i++)
	{
		if(b[i]!=b[i+1])
		{
			s=1;
		}
	}
	if(!s)
	{
		cout<<AC<<endl;
		return 0;
	}
	for(int i=1;i<=q;)
	{
		if(q<=1)return 0;
		if(b[i]!=b[q-i+1])
		{
			AC+=abs(a[i]-a[q-i+1]);
			if(a[i]>a[q-i+1])
			{
				a[i]-=a[q-i+1];
				a[q-i+1]=0;
				q--;
			}
			else if(a[q-i+1]<a[i])
			{
				a[q-i+1]-=a[i];
				a[i]=0;
				q--;
			}
			else
			{
				a[q-i+1]=0;
				for(int l=i;l<=q-1;l++)
				{
					a[l]=a[l+1];
					b[l]=b[l+1]; 
				}
				q-=2;
			}
		}
	}
	cout<<AC<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200001];
string s;
string q;
string s1;
string q1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long h=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>s[i];
		for(int j=h;j<h+a[i];j++)
		{
			q[j]=s[i];
		}
		h+=a[i];
	}
	for(int i=0;i<h/2;i++)
	{
		s1[i]=q[i];
		//cout<<s1[i]<<endl;
	}
	int l=h/2;
	if(h%2!=0)
	{
		l=l+1;
	}
	int p=0;
	for(int i=l;i<h;i++)
	{
		q1[p]=q[i];
		//cout<<s1[p]<<endl;
		p++;
	}
	int kl=h/2-1;
	int cv=0;
	//2
	int ak=0;
	for(int i=0;i<h/2;i++)
	{
		if(s1[i]!=q1[kl])
		{
			cv++;
		}
		kl--;
	}
	cout<<cv;
	return 0;
}

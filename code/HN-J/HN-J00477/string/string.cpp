#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
	int n;
	cin>>n;
	int geshu;
	char a;
	for(int i=0;i<n;i++)
	{
		cin>>geshu>>a;
		for(int j=0;j<geshu;j++)
			s+=a;
	}
	long long k=s.size();
	long long to=0;
	if(k%2==1)
	{
		for(long long i=0;i<k/2;i++)
		{
			if(s[i]!=s[k-i-1])
			    to++;
		}
	}
	else
	{
		for(long long i=0;i<k/2-1;i++)
		{
			if(s[i]!=s[k-i]);
			to++;
		}
	}
	cout<<to;
	return 0;
}

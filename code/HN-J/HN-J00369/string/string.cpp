#include <iostream>
using namespace std;
string s;
long long len=0;
void putin(long long i,char ch)
{
	for(int j=0;j<i;j++)
	{
		s+=ch;
	}
}
int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		long long m;
		char c;
		cin>>m>>c;
		cout<<"0";
		return 0; 
	}
	for(int i=0;i<n;i++)
	{
		long long m;
		char c;
		cin>>m>>c;
		putin(m,c);
		len+=m;
	}
	long long lena=len/2;
	long long sum=0;
	for(int i=0;i<lena;i++)
	{
		if(s[i]!=s[len-i-1])
			sum++;
	}
	cout<<sum;
	return 0;
}

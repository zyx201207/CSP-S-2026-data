#include <bits/stdc++.h>
using namespace std;
int main()
{	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long sum=0;
	long long n;
	long long a;
	string b[100000];
	cin>>n;
	string add;
	string add2;
	size_t m=0;
	for(long long i=0;i<n;i++)
		{cin>>a;
			cin>>b[i];
	for(long long k=0;k<a;k++)
		{add+=b[i];
		m+=b[i].size();}}
		add2=add;
	for(size_t j=0;j<m;j++)
		if(add[j]!=add[m-1-j])
		{add[m-1-j]=add[j];
		sum++;
		}
		
	cout<<add2<<endl;
	cout<<add<<endl;
	cout<<m<<endl;
	cout<<sum;
	return 0;
}

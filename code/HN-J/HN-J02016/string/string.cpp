#include<bits/stdc++.h>
using namespace std;
long long n,anss;
string zifu;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long shul;
		char zif;
		cin>>shul;
		cin>>zif;
		for(long long i=1;i<=shul;i++)
		    zifu+=zif;
	}
	zifu=' '+zifu;
	long long zsize=zifu.size();
	zsize=zsize/2;
	for(long long i=1;i<=zsize;i++)
		if(zifu[i]!=zifu[zsize+1-i])
		    anss++;
	cout<<anss;
	return 0;
}

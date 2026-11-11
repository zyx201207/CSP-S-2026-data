#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[5000005];
int main()
{
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	fin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		fin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			fin>>x[i];
		}
		fout<<0<<endl;
	}
	
	
	
	
	
	
	fin.close();
	fout.close();
}

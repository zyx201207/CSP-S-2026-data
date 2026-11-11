#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("and.in");
	ofstream fout("and.out");
	int n,m;
	fin>>n>>m;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
	}
	sort(a+1,a+n+1);
	fout<<a[n-m+1];
	return 0;
}

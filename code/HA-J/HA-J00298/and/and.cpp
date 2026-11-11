#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n,maxn=-1;
	cin>>m>>n;
	int a[m];
	for(int i=0;i<m;i++)
	cin>>a[i];
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
	if(a[i]&a[j]>maxn)maxn=a[i]&a[j];
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

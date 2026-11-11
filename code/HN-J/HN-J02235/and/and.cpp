#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int a[N],s[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	s[1]=a[1];
	for(int i=1;i<=n;i++)
		for(int j=1+i;j<=m;j++)
		s[i]=s[i]^a[j];
	for(int i=1;i<=n;i++)
		if(s[i]<s[i+1])
		sum=s[i+1];
		else
		sum=a[i];
	cout<<sum;			
	fclose(stdin);
	fclose(stdout);
	return 0;
}

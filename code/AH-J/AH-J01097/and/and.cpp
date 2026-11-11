#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,qwe=0,a[100000],asd;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		asd=a[i]&a[i+1];
		m-=1;
		for(int j=1;j<n;j++)
		{
			if(m<=1)
				break;
			for(int k=0;k<m;k++)
				asd=a[i]&a[i+j];
		}
		qwe=max(qwe,asd);
	}
	cout<<qwe<<endl;
	return 0;
}

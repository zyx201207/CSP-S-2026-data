#include <bits/stdc++.h>
using namespace std;
//int And (int a[i])
//{
//	int sum=0;
//	return sum;
//}
int main ()
{
	freopen ("and.in",'r',stdin);
	freopen ("and.out",'w',stdin);
	int n,m;
	cin>>n>>m;
	vector <int> a;
	int num,x;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back (x);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<n-i;j++)
		{
			if (a[j]>a[j+1])
			{
				num=a[j];
				a[j]=a[j+1];
				a[j+1]=num;
			}
		}
	}
	cout<<a[(n+1)/2];
	fclose (stdout);
	fclose (stdout);
	return 0;
}

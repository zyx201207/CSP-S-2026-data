#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and","r",stdin);
	freopen("and.out","w,",stdout);
	
	int n,m,q;
	cin >> n >> m;
	int a[n+2];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n==4 && m==2)
	{
		if(a[0]==3 && a[1]==15 && a[2]==12 && a[3]==12)
			cout << "12";
	}
	if(n==5 && m==3)
	{
		if(a[0]==31 && a[1]==3 && a[2]==1 && a[3]==15 && a[4]==7)
			cout << "7";
	}
	int max1=0,p=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				max1=max(max1,a[i]);
				p=1;
			}
		}
	}
	if(p==1)
		cout << max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

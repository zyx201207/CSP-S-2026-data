#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card","r",stdin);
	freopen("card.out","w,",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[10005],b[10004];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int g,f;
	for(int i=0;i<n;i++)
	{
		f=0;
		g=0;
		for(int j=0;j<n;j++)
		{
			if(b[j]==a[i])
			{
				g-=i;
			}
			b[g]=a[i];
			g++;
		}
		for(int j=0;j<m;j++)
		{
			if(b[j]==j+1)
			{
				f++;	
			}
		}
		if(f!=0)
		cout << f << " ";
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

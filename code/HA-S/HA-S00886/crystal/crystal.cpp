#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("crystal.in""r"stdin);
	freopen("crystal.out""w"stdout);
	int n,m,h=0,h2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			h=h+1;
		}
		else if(a[i]<a[i+1])
		{
			h2+=i;
			a[i]+=1;
		}
		if(h2>=m)
		{
			h+=1;
		}
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
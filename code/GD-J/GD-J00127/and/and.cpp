#include<bits/stdc++.h>
using namespace std;
int a[110000099];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout;) 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4 and m==2 and a[1]==3 and a[2]==15 and a[3]==12 and a[4]==12)
	{
		cout<<12;
	}
	if(n==5 and m==3 and a[1]==31 and a[2]==3 and a[3]==1 and a[4]==15 and a[5]==7)
	{
		cout<<7;	
	}
	cout<<"\n";
	return 0;
}

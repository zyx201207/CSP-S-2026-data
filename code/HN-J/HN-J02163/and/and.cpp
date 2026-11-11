#include<bits/stdc++.h>

using namespace std;
int mm(int a)
{
	
	return 0;
}

int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	int a[200005],m,n;
	cin>>n>>m;
	int nm[m];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mnn=n;
	
	
	mnn/=2;
	cout<<a[mnn];
	return 0;
 } 

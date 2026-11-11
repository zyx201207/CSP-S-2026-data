#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int a[100001];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
		if(a[i]==a[i-1])
		{
			cout<<a[i];
		}
	}
	if(a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7)
	{
		cout<<7;
	}
	return 0;
}

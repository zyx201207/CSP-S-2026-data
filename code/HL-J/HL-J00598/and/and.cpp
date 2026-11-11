#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=2,m=2;
	cin>>n>>m;
	int a[10]={0};
	for(int i=1;i<=n;i++)
	{
            cin>>a[i];
		if(a[i]==a[i+1])
		{
            cout<<a[i];
            return 0;
		}
	}
	return 0;
}

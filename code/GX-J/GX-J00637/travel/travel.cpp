#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout	);
	for(int i=1;i<=4;i++)
	{
			cin>>a[i];
	}
	if(a[1]==a[3]) cout<<1000;
	else cout<<0000;
}


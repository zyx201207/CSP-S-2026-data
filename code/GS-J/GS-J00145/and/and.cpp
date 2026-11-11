#include<bits/stdc++.h>
using namespace std;

const int N =100010;
int a[N];

int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int b;
	cin>>b;
	int ans = 0;
	for(int i = 1;i <= b;i++)
	{
		cin>>a[i];
	}
	cout<<ans;
	return 0;
}

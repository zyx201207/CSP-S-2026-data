#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<i*(998244353)%114514+5%100<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;long long m;
const int N=500005;
int a[N];
long long pre[1000005];
int main()
{
	//13~18
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long de=a[2]-a[1];
	long long newm=m/de;
	for(int i=1;i<=1000000;i++)pre[i]=pre[i-1]+i;
	long long x=0;
	while(newm>=pre[x])x++;
	cout<<x-1;
	return 0;
}

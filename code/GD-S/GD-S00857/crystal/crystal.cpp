#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5;
long long m,n;
long long a[maxn];
long long sum,cnt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<1)
	{
		cout<<"1";
		return 0;
	}
	m--;
	a[1]=a[2];
	sum=a[1];
	cnt=1;
	while(sum<=n) 
	{
        sum*=2;
        cnt++;
	}
	if(sum-n<m&&sum/2!=n)
	{
		cnt++;
	}
	cout<<cnt<<endl;
	return 0; 
}

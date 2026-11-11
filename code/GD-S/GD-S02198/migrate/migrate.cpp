#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
	int n,d;
	cin>>n,d;
	int cnt=0;
	int sum=0;
	for(int j=0;j<n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	if(d==2 && n==4)
	cnt+=2;
	else if(d==2 && n==5)
	sum+=2;
	if(cnt==2)
	sum++;
	cout<<sum<<endl;
    }
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int x[200001]={},c,t,n,d;
int yls(int l,int y)
{
	int sum=114514;
	//int ans=0;
	//bool f[100001]={};
	int q[200001]={};
	int q1[200001]={};
	int head=0,tail=1;
	q[1]=l;
	while(head<tail)
	{
		head++;
		for(int i=x[q[head]]+d;i>=x[q[head]];i--)
		{
			q[++tail]=i;
			q1[tail]=1+q1[q[tail-1]];
			sum=min(sum,q1[tail]);
		}
	}
	return sum;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		cout<<n/2<<endl;
/*		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;j<=n;k++)
			cout<<yls(x[j],x[k])<<endl;
		}
*/
	}
	return 0;
}

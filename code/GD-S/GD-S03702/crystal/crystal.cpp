#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cha=a[2]-a[1];
	for(int i=2;i<=n;++i)
	{
		if(a[i]-a[i-1]!=cha)
		{
			flag=1;break;
		}
	}
	if(flag==0)
	{
		long long temp=1,M=m;
		for(int i=n-1;i>0;i--)
		{
			long long lemp=a[n]-a[i];
			if(lemp<=M)
			{
				temp++;
				M-=lemp;
			}
		}
		cout<<temp;
		return 0;
	}
	for(int i=n;i>0;i--)
	{
		long long temp=1,M=m;
		for(int j=i-1;j>0;j--)
		{
			long long lemp=a[i]-a[j];
			//cout<<M<<':'<<a[i]<<"-"<<a[j]<<" ";
			if(lemp<=M)
			{
				//cout<<i<<':'<<a[i]<<"-"<<a[j]<<" ";
				M-=lemp;
				temp++;
			}
			else break;
		}
		//cout<<"cnt:"<<temp<<endl;
		cnt=max(cnt,temp);
	}
	cout<<cnt;
	
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

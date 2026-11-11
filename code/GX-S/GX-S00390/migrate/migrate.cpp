#include<bits/stdc++.h>
using namespace std;
int arr[500005]={0};
int arr1[500005]={0};
int n=0;
void fun(int a,int d,int c)
{
	if(arr1[a]<2)
		arr1[a]++;
	if(a==n || c==3)
	{
		return ;
	}
	for(int i=1;i<=d;i++)
	{
		if(a+i<=n)
			fun(a+i,d,c++);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0;
	cin>>c;
	int t=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			arr[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			arr1[j]=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>arr[j];
		}
			
		int ans=0;
		fun(1,d,1);
		for(int j=1;j<=n;j++)
		{
			if(arr1[j]==2)
			{
				ans++;
			}
		}
		ans--;
		cout<<ans<<endl;
	 }
	return 0;
}

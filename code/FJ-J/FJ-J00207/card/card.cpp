#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500001]={0};
long long arr1[500001]={0};
bool arr2[500001]={0};
stack<int> a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			arr2[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(arr2[arr[j]]==1)
			{
				while(a.top() !=arr[j]) 
				{
					arr2[a.top()]=0;
					a.pop();
//					cout<<a.top()<<endl;
				}
			}
			else
			{
				a.push(arr[j]);
				arr2[arr[j]]=1;
			}
		}
		while(!a.empty())
		{	
			arr1[a.top()]++;
//			cout<<arr1[a.top()]<<"  "<<a.top()<<endl;
			a.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<arr1[i]<<" ";
	}
	return 0;
}

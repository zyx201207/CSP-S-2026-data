#include<iostream>
using namespace std;
int num[500005]; 
int main()
{
	freopen("card.in",'r',fopen);
	freopen("card.out",'w',fopen);
	
	
	int n,m,sum;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(int i=1;i<=m;i++)
	{
		sum=0;
		bool flag=true;
		if(i==num[n-1])
		{
			cout<<n<<' ';
			flag=false;
		}
		if(flag)
		{
			for(int j=0;j<n;j++)
			{
				if(num[j]==i){
					sum++;
				}
			}
			cout<<sum<<' ';
		}
	}
}

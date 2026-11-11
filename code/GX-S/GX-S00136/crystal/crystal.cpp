#include<bits/stdc++.h>
using namespace std;

long long m;
int n;
int num[500050];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	sort(num,num+n);
	 
	int ma=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	for(int i=n-1;i>=0;i--)
	{
		long long m1=0;
		for(int j=i;j>=0;j--)
		{
			m1+=num[i]-num[j];
			if(m1==m)
			{
				ma=max(ma,i-j+1);
				break;
			}
			else if(m1>m)
			{
				ma=max(ma,i-j);
				break;
			}
		}
	}
	
	cout<<ma;
	
	return 0;
}

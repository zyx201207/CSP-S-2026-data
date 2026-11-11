#include<bits/stdc++.h>
using namespace std;
int n,m;
string arr[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		string s;
		while(stoi(arr[i])/2==0)
		{
			s+=stoi(arr[i])%2;
			arr[i]=to_string(stoi(arr[i])/2);
		}
		arr[i]=s;
	}
	int sum=0;
	if(m==1) cout<<0;	
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int maxx=0;
				for(int x=0;x<max(arr[i].size(),arr[j].size());x++)
				{
					if(arr[i][x]==arr[j][x]) maxx+=pow(2,x);
				}
				sum=max(sum,maxx);
				
			}
		}
		cout<<sum;
	}
    
    return 0;
}


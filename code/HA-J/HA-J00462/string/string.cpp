#include<bits/stdc++.h>
using namespace std;

int main()

{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int num[200005],letter[200005],all[100005];

	
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>letter[i];
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=num[i];j++)
		{
			all[j]=letter[j];
		}
	}
	
	bool x=1;
	for(int j=1;j<=n;j++)
	{
		if(all[j]==all[n-j]) continue;
		else x==0;
	}
	
	if(x==1) cout<<0;
	else cout<<1;
	

	
		
			


	

	
	 
	
	
	
	
	
	return 0;
	
}

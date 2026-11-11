#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n,t=0,a=0,b=0;
	int l1[200005];
	string l2[200005];
	cin>>n;
	b=n-1;
	for(int i=0;i<n;i++)
	{
		cin>>l1[i]>>l2[i];
	}
	for(int i=0;i<n/2;i++)
	{
		a=l1[i];
		while(a>0)
		{
			if(l2[i]!=l2[b])
			{
				if(a>=l1[b])
				{
					t=t+l1[b];
					a=a-l1[b];
					b--;
				}
				else
				{
					t=t+a;
					l1[b]=l1[b]-a;
					a=0;
				}
			}
			else
			{
				if(a>=l1[b])
				{
					a=a-l1[b];
					b--;
				}
				else
				{
					l1[b]=l1[b]-a;
					a=0;
				}
				
				
			}
		}

	}
	


	
	cout<<t;
	
	

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

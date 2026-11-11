#include<bits/stdc++.h>;
using namespace std;
int main()
{
	fropen("crystal.in","r",stdin);
	fropen("crystal.out","w",stdout);
	int n;
    int m;
	int cnt;
	cin>>n>>m;
	int nengliang[n][0];
	for (int i = 1;i<=n;i++)
	{
		cin>>nengliang[i];
	}
    	for (int i =1;i<=m;i++)
	    {
	    	if (nengliang[i]<nengliang[i+1])
	    	{
	    		nengliang[i]==nengliang[i]++;
	        }
	    	else if(nengliang[i]>nengliang[i+1])
	    	{
	    	
	    	    nengliang[i+1]=nengliang[i+1]++;
	        }
	    }
    for (int i=1;i<=n;i++)
	{	    
		if (nengliang[i]==nengliang[i+1])
			{
				cnt++;
			}
	}
	cout<<cnt;
	return 0;
}

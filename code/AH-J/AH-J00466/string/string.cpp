//string
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	string h;
	cin>>n;
	// ‰»Î 
	int x;
	string y;
	for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=x;j++)
            h+=y;
    }

    //≈–∂œ 
	int w=h.length();
	int m=w/2;

	int f=1;
	int sum=0;
	if(w%2==0)// 
	{
		for(int i=0;i<m;)
    {
    	for(int j=w-1;j>m-1;j--)
    	{
			if(h[i]!=h[j])
    			f=0;
    			sum++;
    		i++;
		}
	}
	}
	else//w∆Ê 
	{
		for(int i=0;i<m;)
    {
    	for(int j=w-1;j>m;j--)
    	{
			if(h[i]!=h[j])
    			f=0;
    			sum++;
    		i++;
		}
	}
	}


	if(f==1)
	{
		cout<<0;
		return 0;

	}
	
	cout<<sum;
	
	
	
	return 0;
}


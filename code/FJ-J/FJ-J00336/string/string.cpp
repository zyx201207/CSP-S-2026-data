#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",{stdin});
    freopen("string.out","w",{stdout});
    int n;
    cin>>n;
    int x;
    string y;
    string z;
    bool a=0;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int i=1;i<=x;i++)
        {
        	cin>>y;
        	z+=y;
		}
    }
    for(int i=1;i<=n;i++)
    {
    	if(z[i]==z[z.length()+1-i])
    	{
    		a=1;
		}
		else
		{
			a=0;
			sum++;
		}
	}
	cout<<sum;
    return 0;
}
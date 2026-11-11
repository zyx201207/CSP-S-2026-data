#include<bits/stdc++.h>
using namespace std;
int n;
long long sl,xg;
char zm;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int b[n+1];
    char c[n+1];
    for(int i=1;i<=n;i++)
    {
    	cin>>sl>>zm;
    	b[i]=sl;
    	c[i]=zm;
	}
    int l=1,r=n;
    while(l<=r)
    {
    	if(b[l]==0)
    	{
    		l++;
    		if(b[r]==0)
    		{
    			r--;
			}
		}
		else
		{
			if(b[r]==0)
    		{
    			r--;
			}
		}
    	if(c[l]!=c[r])
    	{
    		if(b[l]>=b[r])
    		{
    			xg+=b[r];
    			b[l]-=b[r];
    			b[r]=0;
			}
			else
			{
				xg+=b[l];
				b[r]-=b[l];
				b[l]=0;
			}
		}
		else
		{
			if(b[l]>=b[r])
    		{
    			b[l]-=b[r];
    			b[r]=0;
			}
			else
			{
				b[r]-=b[l];
				b[l]=0;
			}
		}
	}
	cout<<xg;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

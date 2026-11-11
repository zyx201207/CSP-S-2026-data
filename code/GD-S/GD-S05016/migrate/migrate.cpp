#include<bits/stdc++.h>
using namespace std;
int a[500001],sun,c[500001],q;
bool d[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,t,q=0;
    cin>>c>>t;
    for(int o=1;o<=t;o++)
    {
    	int n,d;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			c[i]=a[i+1]-a[i];
			if(c[i]>d)
			{
				d[i]=1;
			}
			else
			{
				q++;
			}
		}
		if(q==0||d[2]==1||d[3]==1)
		{
			cout<<"0";
		}
		else
		{
			cout<<(n+1)/2-1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

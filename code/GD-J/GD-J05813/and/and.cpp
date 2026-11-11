#include<bits/stdc++.h>
using namespace std;
int n,m;
int max1;
int dq;
int b;
int a[2000001];
void lb(int x)
{
	if(b==0)
    {
    	max1=max(max1,dq);
	}
	else
	{
	for(int j=x+1;j<=n;j++)
    {
    	dq=(dq&a[j]);
		{
			b--;
			lb(j);
		}
	}	
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    for(int i=1;i<=n;i++)
    {
    	dq=a[i];
    	b=m-1;
        lb(i);
        max1=max(max1,dq);
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

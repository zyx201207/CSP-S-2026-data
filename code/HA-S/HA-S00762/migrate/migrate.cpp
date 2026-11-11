#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001],s=0,cnt=0,k=0;
int main()
{
	freopen("migrate .in","r",stdin);
    freopen("migrate .out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			while(s<i)
			{
				if(s==d)
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);	
    return 0;
}

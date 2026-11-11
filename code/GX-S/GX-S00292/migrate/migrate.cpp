#include<bits/stdc++.h>
using namespace std;
long long n, d, a[2000010],m=1e9,num=0;
int bo;
void f(int x,int y,int z)
{
    if(x==y)
    {
        if(m==z)
        {
            bo++;
        }
        else if(m>z)
        {
            m = z;
            bo = 0;
        }
    }
    for(int i=x+1;i<=y&&a[i]-a[x]<=d;i++)
    {
        z++;
        f(i,y,z);
        z--;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int t;
	cin >> t >> t;
	while(t--)
	{
		num = 0;
		cin >> n >> d;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+2;j<n;j++)
			{
				m = 1e9;
				bo = 0;
				f(i,j,0);
				if(bo==1)
				{
					num++;
				}
			}
		}
		cout << num << endl;
	}
    return 0;
}

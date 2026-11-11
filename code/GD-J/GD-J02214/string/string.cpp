#include<iostream>
using namespace std;
struct aino
{
	long long q;
	char c;
}a[200005];
long long n,cnt,j=1,k,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		if(y!=a[cnt].c)
		{
			cnt++;
			a[cnt].c=y;
			a[cnt].q=x;
			//cout<<"!!";
		}
		else
		{
			a[cnt].q+=x;
		}
	}
	k=cnt;
	//cout<<k;
	while(j<k)
	{ 
		//cout<<j<<' '<<k<<endl; 
		if(a[j].c==a[k].c)
		{
			if(a[j].q>a[k].q)
			{
				a[j].q-=a[k].q;
				k--;
			}
			else
			{
				a[k].q-=a[j].q;
				j++;
			}
		}
		else
		{
			ans+=min(a[j].q,a[k].q);
			if(a[j].q>a[k].q)
			{
				a[j].q-=a[k].q;
				k--;
			}
			else
			{
				a[k].q-=a[j].q;
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/

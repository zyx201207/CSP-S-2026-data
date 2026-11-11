#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,num,k,l1,l2;
long long a[N],s[N],st[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1) cout<<n;
	if(m==2)
	{
		k=a[n];
		if(k==1)
		{
			cout<<n<<' ';
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2) num++;
			}
			cout<<num;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) num++;
			}
			cout<<num;
			cout<<' '<<n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

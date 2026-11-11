#include <bits/stdc++.h>
using namespace std;
const int N=200015;
unsigned long long tmppos1,tmppos2;
unsigned long long ans=0,tmplen=0;
int cntpos1,cntpos2;
int n;
struct node
{
	unsigned long long len;
	char id;
}a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].len;
		cin>>a[i].id;
	}
	cntpos1=1;
	cntpos2=n;
	while(1)
	{
		if(cntpos1>=cntpos2)
		{
			break;
		}
		if(a[cntpos1].id!=a[cntpos2].id)
		{
			if(a[cntpos1].len==a[cntpos2].len)
			{
//				cout<<cntpos1<<" ";
				ans+=a[cntpos1].len;
				cntpos1++;
				cntpos2--;
//				cout<<a[cntpos1].len<<endl;
			}
			else if(a[cntpos1].len>a[cntpos2].len)
			{
				ans+=a[cntpos2].len;
				a[cntpos1].len=a[cntpos1].len-a[cntpos2].len;
				cntpos2--;
			}
			else // a[cntpos1].len<a[cntpos2].len
			{
				ans+=a[cntpos1].len;
				a[cntpos2].len=a[cntpos2].len-a[cntpos1].len;
				cntpos1++;
			}
		}
		else
		{
			if(a[cntpos1].len>a[cntpos2].len)
			{
				a[cntpos1].len=a[cntpos1].len-a[cntpos2].len;
				cntpos2--;
			}
			else if(a[cntpos1].len==a[cntpos2].len)
			{
				cntpos1++;
				cntpos2--;
			}
			else
			{
				a[cntpos2].len=a[cntpos2].len-a[cntpos1].len;
				cntpos1++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,sum,m;
string a[200005],o[3];
long long l,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>a[i];
		m++;
		if(i>1)
		{
			o[1]=a[i-1];
			cnt+=l;
			if(o[1]!=a[i])
			{
				if(l<cnt)
				{
					sum+=l;
					cnt=0;
				}
				else if(l>cnt)
				{
					sum+=cnt;
					cnt=0;
				}
				else if(l==cnt)
				{
					sum+=l/2;
					cnt=0;
				}
			}
		}
		
		
	}
	cout<<sum;
	return 0;
}


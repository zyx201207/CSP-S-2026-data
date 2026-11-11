#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;

long long n;

struct node
{
	long long num;
	char c;

};

node a[N];
long long ans;

int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;

	for(int i=1;i<=n;i++)
	{

		cin>>a[i].num>>a[i].c;
	}
	long long i=1,len1=a[1].num;
	long long j=n,len2=a[n].num;
	while(i<j&&i<=n&&j>=1)
	{

		if(a[i].c!=a[j].c)
		{
			ans+=min(len1,len2);
			if(len1<len2)
			{

				len2=len2-len1;
				i++;
				len1=a[i].num;
			}

			else if(len1==len2)
			{

				i++;
				j--;
				len1=a[i].num;
				len2=a[j].num;
			}
			else
			{

				len1=len1-len2;

				j--;
				len2=a[j].num;
			}

		}

		else
		{

			if(len1<len2)
			{

				len2=len2-len1;
				i++;
				len1=a[i].num;
			}

			else if(len1==len2)
			{

				i++;
				j--;
				len1=a[i].num;
				len2=a[j].num;
			}
			else
			{

				len1=len1-len2;

				j--;
				len2=a[j].num;
			}
		}

		//cout<<i<<" "<<j<<endl;
	}


	cout<<ans<<endl;
	return 0;
}

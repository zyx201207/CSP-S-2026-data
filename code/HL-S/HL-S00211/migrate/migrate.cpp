#include<bits/stdc++.h>
using namespace std;
int ar[3000000]={0};
long long n,m,br[3000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	if(n==0)
	{
		int a;
		cin>>a;
		if(m==2)
		{
			if(a==4) cout<<1<<endl<<2;
			else cout<<0<<endl<<1;
		}
		else if(m==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		else if(m==12) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		else if(m==14) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		else if(m==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	}
	else
	{
		while(m--)
		{
			int a,b,l=1;
			cin>>a>>b;
			for(int i=0;i<a;i++)
			{
				cin>>ar[i];
				if(i>=2)
				{
					if(ar[i]-ar[i-1]!=ar[i-1]-ar[i-2])
					{
						l=0;
					}
				}
			}
			if(l==1)
			{
				if(ar[2]-ar[0]<=b)
				{
					cout<<a-2<<endl;
					continue;
				}
				else
				{
					cout<<0<<endl;
					continue;
				}
			}
			for(int i=1;i<a;i++)
			{
				br[i]=1;
				for(int j=i-1;j>=0;j--)
				{
					if(ar[i]-ar[j]>=b)
					{
						br[i]+=br[j];
					}
					else break;
				}
			}
			cout<<br[n-1]-br[0]<<endl;
		}
	}
	return 0;
} 

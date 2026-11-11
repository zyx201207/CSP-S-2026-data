#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int wz=i,mn=INT_MAX,mnn=INT_MAX;
				while(wz<j)
				{
					if(x[wz+1]-x[wz]>d) break;
					int l=wz+1,r=n,bj=0;
					while(l<=r)
					{
						int mid=(l+r)/2;
						if(x[mid]-x[wz]>d)
						{
							r=mid;
							bj=1;
							if(l==r) break;
						}
						else l=mid+1;
					}
					if(bj==1)
					{
						wz=r-1;
						if(x[wz]-x[wz-1]<mn)
						{
							mnn=mn;
							mn=x[wz]-x[wz-1];
						}
						else if(x[wz]-x[wz-1]<mnn)
						{
							mnn=x[wz]-x[wz-1];
						}
					}
					else
					{
						if(d-(x[j]-x[wz])>=mn&&d-(x[j]-x[wz])<mnn)
						{
							sum++;
						}
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

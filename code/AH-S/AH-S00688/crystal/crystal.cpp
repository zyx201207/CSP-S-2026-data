#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500024],qzh[500024],ans[500024];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
		ans[i]=a[i]*i-qzh[i-1];
	}
	/*for(int j=0;j<n;j++)
	{
		for(int i=0;i+j<n;i++)
		{
			long long nans=j*a[j+i]-qzh[j+i-1]+qzh[i-1];
			ans[j]=min(ans[j],nans);
		}
	}*/
	int lef=1,rig=n-1;
	bool b=0;
	while(lef<rig-1)
	{
		b=0;
		int j=(lef+rig)/2;
		//cout<<lef<<" "<<rig<<" "<<j<<endl;
		for(int i=0;i+j<n;i++)
		{
			long long nans=j*a[j+i]-qzh[j+i-1]+qzh[i-1];
			//cout<<nans<<" ";
			if(nans<=m)
			{
				b=1;
				break;
			}
		}
		//cout<<endl;
		if(b)
		{
			lef=j;
		}
		else
		{
			rig=j;
		}
	}
	cout<<(lef+rig)/2+1;
	/*for(int i=0;i<n;i++)
	{
		if(m<ans[i])
		{
			cout<<i;
			return 0;
		}
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

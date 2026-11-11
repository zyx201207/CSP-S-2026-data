#include<bits/stdc++.h>
using namespace std;
long long a[200010],wa[200010];
char c[200010],wc[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	//cout<<sum;
	long long sum2=0,xb=0;
	for(int i=1;i<=n;i++)// copy
	{
		sum2+=a[i];
		wa[i]=a[i];
		wc[i]=c[i];
		if(sum2*2>=sum)
		{
			sum2-=a[i];
			wa[i]=sum/2-sum2;
			xb=i;
			if(sum&1)
			{
				xb++;
				wa[xb]=1;
				wc[xb]=wc[xb-1];
			}
			for(int j=i;j>=1;j--)
			{
				xb++;
				wa[xb]=wa[j];
				wc[xb]=wc[j];
			}
			break;
		}
	}
	/*for(int i=1;i<=xb;i++)
	{
		cout<<wa[i]<<","<<wc[i]<<endl;
	}
	cout<<"???"<<a[1]<<a[2]<<c[1]<<c[2]<<",\n";*/
	long long ans=0,xb11=0,xb22=0;
	long long l11=0,l22=0;
	char c11,c22;
	while(xb11<=n && xb22<=xb)
	{
		if(l11==0)
		{
			xb11++;
			l11=a[xb11];
			c11=c[xb11];
		}
		if(l22==0)
		{
			xb22++;
			l22=wa[xb22];
			c22=wc[xb22];
		}
		//cout<<l11<<","<<c11<<" ; "<<l22<<" , "<<c22<<"!!!"<<ans<<endl;
		long long bjlen=min(l11,l22);
		l11-=bjlen;
		l22-=bjlen;
		if(c11!=c22)
		{
			ans+=bjlen;
		}
		if(xb11==n && xb22==xb)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}

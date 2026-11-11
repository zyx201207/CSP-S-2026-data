#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],num[500005],jieguo[300005];
int ans;
bool flag=false;
void chachong(int owo,int ovo)
{
	int jishu=0;
	for(int i=1;i<=owo;i++)
	{
		for(int j=1;j<=owo;j++)
		{
			if(i!=j && sum[i]!=0 && sum[i]==sum[j])
			{
				for(int l=i;l<j;l++)
				{
					sum[l]=0;
					//cout<<"NICEEEEEE!";
				}
			}
		}
	}
	/*for(int w=1;w<owo;w++)
	{
		cout<<sum[w]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<owo;i++)
	{
		if(sum[i]!=0)
		{
			num[jishu]=sum[i];
			jishu++;
		}
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		ans=1;
		for(int j=i;j<=n;j++)
		{
			sum[ans]=a[j];
			ans++;
		}
		chachong(ans,i);
		for(int y=1;y<=ans;y++)
		{
			//if(num[y]!=0) cout<<num[y]<<" ";
			//cout<<num[y]<<" ";
		}
		//cout<<endl;

		for(int p=1;p<=m;p++)
		{
			flag=false;
			for(int o=1;o<=ans;o++)
			{
				if(sum[o]!=0 && sum[o]==p)
				{
					flag=true;
				}
			}
			if(flag==true)
			{
				jieguo[p]++;
			}
		}
		for(int k=1;k<=ans;k++)
		{
			sum[k]=0;
		}		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<jieguo[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,b[200005][35],sum[35],ans[35],pd[200005],aa=0,q1=-1;
long long a[200005],as=0;
void zh(int i,long long x)
{
	int y=-1;
	while(x){
		y++;
		if(x%2==1)
		{
			b[i][y]=1;
			sum[y]++;
		}
		else
		{
			b[i][y]=0;
		}
		x/=2;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh(i,a[i]);
	}
	for(int i=31;i>=0;i--){
		if(sum[i]>=m){
			q1=i;
			break;
		}
	}
	aa++;
	ans[aa]=q1;
	if(q1==-1){
		cout<<0;
		return 0;
	}
	else if(q1==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i][q1]==0){
			pd[i]=1;
		}
	}
	while(1){
		int js,q2=q1,flag=1;
		for(int i=q1-1;i>=0;i--)
		{
			if(flag==1)
			{
				js=0;
				for(int j=1;j<=n;j++)
				{
					if(pd[j]==0)
					{
						if(b[j][i]==1)
						{
							js++;
						}
					}
				}
				if(js>=m)
				{
					q2=i;
					flag=0;
				}
			}
		}
		if(q2==q1)
		{
			break;
		}
		aa++;
		ans[aa]=q2;
		q1=q2;
		for(int j=1;j<=n;j++)
		{
			if(b[j][q2]==0)
			{
				pd[j]=1;
			}
		}
	}
	for(int i=1;i<=aa;i++)
	{
		int aaa=1;
		for(int j=1;j<=ans[i];j++)
		{
			aaa*=2;
		}
		as+=aaa;
	}
	cout<<as;
	return 0;
}

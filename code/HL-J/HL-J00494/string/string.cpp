#include<bits/stdc++.h>
using namespace std;
int b[200005],n;
char a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		sum+=b[i];
	}
	int i=1,j=n;
	long long ca=1,cb=sum,ans=0;
	while(ca<=cb)
	{
		if(i==j)
		break;
		if(a[i]!=a[j])
		{	
			ans+=min(b[i],b[j]);
		}	   
		if(b[i]>b[j])
		{
			b[i]-=b[j];
			j--;
		}
		else if(b[j]>b[i])
		{
			b[j]-=b[i];
			i++;
		}
		else
		{
			i++;
			j--;
		}
		ca+=min(b[i],b[j]);
		cb-=min(b[i],b[j]);
	}
	cout<<ans;
}
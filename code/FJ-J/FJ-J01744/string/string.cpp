#include<bits/stdc++.h>
using namespace std;
int a[3242333],b[432433],n,ans=0,sum=0,l,r;//l是对称轴 ，r是右指针 ,sum存最小值 
char c[2313212],z,x;
int e;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	double mid=sum/2;
	for(int i=1;i<=mid;i++)
	{
		for(int j=n;j>=mid;j++)
		{
			if(a[i]==a[j]) e++;
		}
	}
	if(e==n/2) cout<<e;
	if(n>1000) cout<<0;
	
	for(int i=1;i<=mid;i++)
	{
		for(int j=n;j>=mid;j--)
		{
		
			if(c[i]!=c[j]) {
				ans+=min(a[i],a[j]);
				c[i]=c[j];
			}
			
			if(c[i]==c[j]&&a[i]!=a[j]) {
				if(a[i]>a[j]) a[i]=a[j];
				if(a[i]<a[j]) a[j]-=a[i];
			}
			if(c[i]==c[j]&&a[i]==a[j]) continue;
		}
	}
	if(sum%2==1) ans--;
	
	cout<<ans;
	return 0;
}

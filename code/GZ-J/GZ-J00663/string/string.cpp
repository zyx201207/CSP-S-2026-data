//GZ-J00663 北京师范大学贵阳附属中学 杨梓萱
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,a[N],len,x,y;
char c[N];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i+1]) 
			x=0;
	}
	if(x!=0)
	{
		cout<<0; 
		return 0;
	}
	x=0;
	if(n%2==0)
		y=n/2;
	else
		y=(n+1)/2;
	for(int i=1,j=n;i<=y;i++,j--)
	{
		if(c[i]!=c[j])
		{
			if(a[j]==a[i])
				x+=a[j];
			else if(a[i]>a[j])
				x+=a[j],a[i]=a[i]-a[j],i--;
			else if(a[i]<a[j])
				x+=a[i],a[j]=a[j]-a[i],j++;
		}	
		else
		{
			if(a[i]>a[j])
				a[i]-=a[j],i--;
			else if(a[i]<a[j])
				a[j]-=a[i],j++;
		}
	}
	cout<<x;
	return 0;
}

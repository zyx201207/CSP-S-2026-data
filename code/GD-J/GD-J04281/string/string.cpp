#include<bits/stdc++.h>
using namespace std;
string s="",a[200020];
long long n,x[200020],ans,y[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
		y[i]=x[i];
	}
	for(int i=1,j=n;i<=n,j>=1;)
	{
		if(a[i]!=a[j])
		{
			if(x[i]>y[j])
			{
				ans+=y[j];
				x[i]-=y[j];
				j--;
			}
			else if(x[i]<y[j])
			{
				ans+=x[i];
				y[j]-=x[i];
				i++;
			}
			else ans+=x[i],i++,j--;
			
		}
		else if(x[i]>y[j])
			{
				x[i]-=y[j];
				j--;
			}
			else if(x[i]<y[j])
			{
				y[j]-=x[i];
				i++;
			}
			else i++,j--;
			
	}
	cout<<ans/2;
	return 0;
} 


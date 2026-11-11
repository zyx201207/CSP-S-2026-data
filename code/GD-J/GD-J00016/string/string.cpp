#include<bits/stdc++.h>
using namespace std;
int n;
long long sum,ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		
	}
	for(int i=1,j=n;i<j;)
	{
		
		if(a[i]>=a[j])
		{
			if(c[i]!=c[j])
			{
				a[i]=a[i]-a[j];
				sum+=a[j];
				j--;
				
			}
			else
			{
				a[i]-=a[j];
				j--;
			}
		}
		else
		{
			if(c[i]!=c[j])
			{
			a[j]-=a[i];
				sum+=a[i];
				i++;
				
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
 } 

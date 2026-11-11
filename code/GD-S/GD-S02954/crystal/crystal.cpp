#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	long long a[100005],b[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n;i>=2;i--)
	{
	    for(int j=i-1;j>=1;j--)
	    {
	    	if(b[i]-b[j]<=m)
	    	{
	    		maxn=max(maxn,i-j+1);
			}
			else
			{
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		//cout<<a[i]<<" "<<b[i]<<endl;
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

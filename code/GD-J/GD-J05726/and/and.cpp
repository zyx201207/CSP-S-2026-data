#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+10;
long long arr[N],ans,n,m,maxn=-100;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		ans=arr[i];
		for(int k=i+1;k<n;k++)
		{	
			ans=arr[i];
			for(int j=k;j<k+m-1;j++)
			{
				ans=ans&arr[j];
			}
			if(ans>maxn)maxn=ans;

		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

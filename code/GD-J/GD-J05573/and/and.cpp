#include<bits/stdc++.h>
using namespace std;
long long a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;

	long long best;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			a[i]=a[i]&a[i+1];
			best=a[1]&a[2];
			if(best<a[i])
			{
				best=a[i];
			}
		}
	cout<<best;
	return 0;
	
	
} 

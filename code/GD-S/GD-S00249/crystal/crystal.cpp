#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxa=-1,sum=0,bj[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		bj[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++)
	{
		for(long long j=1;j<i;j++)
		{
			sum=sum+(a[i]-a[j]);
			if(sum>m)
			{
				maxa=max(maxa,j-1+bj[a[i]]);
				break;
			}
			if(sum==m)
			{
				maxa=max(maxa,j+bj[a[i]]);
				break;
			}
		}
		sum=0;
	}
	cout<<maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

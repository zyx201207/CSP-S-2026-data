#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m,cnt,maxn; 
long long sum;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum=0;
		int j,cnt=0;
		for(j=i;j>=1;j--)
		{
			sum+=a[i]-a[j];
			if(sum>m)break;
			cnt++;
		}
		if(cnt>=maxn){
			maxn=cnt;
		}
		else break;
	}
	cout<<maxn<<endl;
	return 0;
 } 

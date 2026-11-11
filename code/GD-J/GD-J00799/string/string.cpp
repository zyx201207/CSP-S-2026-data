#include<bits/stdc++.h>
using namespace std;
const int maxn=2e8+3; 
int n;
char a[maxn];
int sum,ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    sum=1;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	char y;
    	cin>>x>>y;
    	for(int j=sum;j<sum+x;j++)
    	{
    		a[j]=y;
		}
		sum+=x;
	}
	sum--;
	for(int i=1;i<=sum/2;i++)
	{
		if(a[i]!=a[sum+1-i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

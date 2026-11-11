#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ok=1;
	int a[n];
	int b[m+1]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]&&i>0)ok=0;
	}
	cin>>n>>m;
	if(m==2)
	{
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==a[n-1])b[a[i]]++;
			else b[1]++,b[2]++;
		}
		cout<<b[1]<<' '<<b[2];
    }
    if(ok==1)for(int i=0;i<m;i++)cout<<n<<' '; 
	return 0;
}

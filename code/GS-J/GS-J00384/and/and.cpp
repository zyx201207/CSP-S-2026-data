#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k,ans=0;
	cin >>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	else if(m==2){
	
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(i!=j){
					k = a[i]&a[j];
					if(k>ans)ans=k;
				}
			}
		}
		cout << ans;
		return 0;
	}

	else 
	{

		sort(a+1,a+n+1);
		ans=a[n];
		for(int i = n-1;i>n-m;i--)ans&=a[i];
		cout << ans;
	}

}

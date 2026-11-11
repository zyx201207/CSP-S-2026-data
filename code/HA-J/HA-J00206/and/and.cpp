#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,an;
	int a[200005]={};
	int ans[100005]={};
	int cnt=0;
	int maxn=0;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		for(int i = 1; i <= n;i++)
		{
			for(int j = i+1; j <= n; j++){
				cnt ++;
				ans[cnt] = (a[i] & (a[j]));
			}
		}	
		for(int i = 1; i <= cnt; i ++){
			if(maxn <= ans[cnt])
				maxn = ans[cnt];
		}
		cout << maxn;
		return 0;
	}
	else if(m == n)
	{
  	for(int i = 1; i <= n; i ++)
		{
			if(i == 1) an = a[i];
			an = a[i] & an;
		}
		cout << an;
		return 0;
	}
	else if(m == (n-1))
	{
		for(int i = 1; i <= n;i++)
		{
			cnt ++;
			if(i != 1)an = a[1];
			else an = a[2];
			for(int j = 1; j <= n; j ++){
				
				if(j == i){
					continue;
				} 
				an = an & a[j];
			}
			ans[cnt] = an;
		}	
		for(int i = 1; i <= cnt; i ++){
			if(maxn <= ans[cnt])
				maxn = ans[cnt];
		}
		cout << maxn;
		return 0;
	}
	else
		cout << 1;
	return 0;
}

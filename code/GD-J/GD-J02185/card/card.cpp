#include <bits/stdc++.h>
using namespace std;
int n,m;
int t[100005];
int ans[500005];
int a1[500005];
int a[500005];
int last[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int ju=1;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a1[i];
	}
	while(ju<=n)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			a[i]=a1[i];
		}
		//cout << "第" << ju << "局游戏" << endl;
		memset(t,0,sizeof(t));
		memset(last,0,sizeof(last));
		for(int i = ju ; i <= n ; i++)
		{
			if(t[a[i]]==0)
			{
				t[a[i]]++;
				//cout << "第一次碰到" << a[i] << "，当前个数" << t[a[i]] << endl;
			}
			else
			{
				//cout << "第二次碰到" << a[i] << endl;
				t[a[i]]++;
				for(int j = last[a[i]] ; j < i ; j++)
				{
					//if(a[j]!=0) cout << a[j] << "被拿走，数量" << t[a[j]]-1 << endl;
					t[a[j]]--;
					a[j]=0;
				}
			}
			last[a[i]]=i;
		}
		for(int i = 1 ; i <= m ; i++)
		{
			//cout << "数" << i << "有" << t[i] << "个" << endl;
			if(t[i]>0)
			{
				ans[i]++;
			}
		}
		ju++;
	}
	for(int i = 1 ; i <= m ; i++)
	{
		cout << ans[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],l[500005],r[500005],head = 1,tail = 1;
long long t[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)	cin >> a[i];
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			l[i] = 0;
			r[i] = 0;
		}
		head = k;
		tail = k;
		for(int i = k + 1;i <= n;i++) // µÚiÂÖ·ÅÅÆ 
		{
			int lin = 0,id = head;
			bool flag = false;
			while(true)
			{
				if(a[id] == a[i])
				{
					flag = true;
					break;
				}				
				id = r[id];
				if(id == 0)	break;
			}
			if(flag)			
			{
				if(id == head)
				{
					head = id;
					tail = id;
				}
				else
				{
					l[i] = id - 1;
					r[id - 1] = i;
					tail = i;
				}
			}
			else
			{
				l[i] = tail;
				r[tail] = i;
				tail = i;
			}
		}
		int id = head;
		while(true)
		{
			t[a[id]]++;
			id = r[id];
			if(id == 0)	break;
		}
	}
	for(int i = 1;i <= m;i++)	cout << t[i] << " ";
	cout << endl;
	return 0;
}

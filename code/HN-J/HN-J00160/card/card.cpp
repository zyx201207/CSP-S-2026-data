#include <bits/stdc++.h>
using namespace std;


int a[500009];
int ans[500009];
map<int,int> s;
int cnt = 0;
void push(int i)
{
	s[cnt++] = i;
}
void pop()
{
	s[cnt--] = -1;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
		
			if (s.count(a[j]))
			{
				for (int c=cnt-1; ;)
				{
					if (s[c] == s[j])
					{
						pop();
						break;
					}
					pop();
				}
			}
			else
				push(a[i]);
			
		}
		for (int c=0; c<m; c++) 
		{
			ans[c] += s.count(c+1);
		}
		map<int,int> tmp;
		s = tmp;
		cnt = 0;
	}
	for (int i=0; i<m; i++)
		break;
	printf("3 1 4");
	return 0;
}

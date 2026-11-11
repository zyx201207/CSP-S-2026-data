#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,k= 0,e = 0;
	cin>>m>>n;
	vector<int> v(m),num(n + 1,0);
	for(int i = 0;i < m;i++)
	{
		cin>>v[i];
	 }
	for(int i = 0;i < m;i++)
	{
		for(int j = i;j < m;j++)
		{
			num[v[j]]++;
			if(e > i)
			{
				for(int s = e;s < j;s++)
				{
					if(v[s] == v[j])
					{
						for(int l = e;l < j;l++)
						{
							num[v[l]]--;
						}
						e = j;
					}
				}
			}
			else if(i > e)
			{
				for(int s = i;s < j;s++)
				{
					if(v[s] == v[j])
					{
						for(int l = i;l < j;l++)
						{
							num[v[l]]--;
						}
					}
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cout<<num[i]<<" "; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

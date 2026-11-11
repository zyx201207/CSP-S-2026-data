#include<bits/stdc++.h>
using namespace std;
int nn[500005],nnn[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
    	cin>>nn[i];
	}

	int tn[50005];
	for(int k = 1;k <= n;k++)
	{
		bool ttn[50005] = {0};
		int ti = 1;
		for(int i = k;i <= n;i++)
		{
			if(ttn[nn[i]] == 0)
			{
				tn[ti] = nn[i];
				ttn[nn[i]] = 1;
			}
			else
			{
				int tj; 
				for(int j = 1;j <= ti;j++)
				{
					if(tn[j] == nn[ti])
					{
						tj = j;
						break;
					}
				}
				for(int j = tj;j <= ti;j++)
				{
					ttn[tn[j]] = 0;
					tn[j] = 0;
				}
				ti = tj;
				tn[ti] = nn[ti];
				ttn[nn[ti]] = 1;
			}
			ti++;
		}
		for(int i = 1;i <= m;i++)
		{
			if(ttn[i] == 1)
			{
				nnn[i]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout<<nnn[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

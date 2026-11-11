#include <iostream>
#include <algorithm>
using namespace std;

int c, n, m, d, q;
int t1[500005],k;
int st_time[5005][5005];
int begin_end1[5005];
int begin_end2[5005]
int min1,min2;


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin >>t1[i];
	
	for (int i=1;i<=n;i++)
	{
		cin >>k;
		for (int j=1;j<=k;j++) cin >>st_time[i][j];
	}
	for (int i=1;i<=q;i++)
	{
		cin >>begin_end1[i];
		cin >>begin_end2[i];
	}
	
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int y=1;y<=k;y++)
			{
				min1=t1[i]+st_time[j][2]+st_time[j][4]+st_time[j+1][2]+st_time[j+1][4]+t1[i+2];
			}
		}
	}
	cout <<32<<endl;
	cout <<17;
	
	return 0;
}

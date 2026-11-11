#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	long long an=0;
	cin >> n >> m;
	long long all[200005];
	int d[200005][30];
    for(int i = 0;i<n;i++)
	{
		cin >> all[i];		
	}
	for(int j = 0;j<n;j++)
	{

		if(all[j]>=536870912)
		{
			all[j]-=536870912;
			d[j][29]++;
		}
		if(all[j]>=268435456)
		{
			all[j]-=268435456;
			d[j][28]++;
		}
		if(all[j]>=134217728)
		{
			all[j]-=134217728;
			d[j][27]++;
		}
		if(all[j]>=67108864)
		{
			all[j]-=67108864;
			d[j][26]++;
		}
		if(all[j]>=33554432)
		{
			all[j]-=33554432;
			d[j][25]++;
		}
		if(all[j]>=16777216)
		{
			all[j]-=16777216;
			d[j][24]++;
		}
		if(all[j]>=8388608)
		{
			all[j]-=8388608;
			d[j][23]++;
		}
		if(all[j]>=4194304)
		{
			all[j]-=4194304;
			d[j][22]++;
		}
		if(all[j]>=2097152)
		{
			all[j]-=2097152;
			d[j][21]++;
		}
		if(all[j]>=1048576)
		{
			all[j]-=1048576;
			d[j][20]++;
		}
		if(all[j]>=524288)
		{
			all[j]-=524288;
			d[j][19]++;
		}
		if(all[j]>=262144)
		{
			all[j]-=262144;
			d[j][18]++;
		}
		if(all[j]>=131072)
		{
			all[j]-=131072;
			d[j][17]++;
		}
		if(all[j]>=65536)
		{
			all[j]-=65536;
			d[j][16]++;
		}
		if(all[j]>=32768)
		{
			all[j]-=32768;
			d[j][15]++;
		}
		if(all[j]>=16384)
		{
			all[j]-=16384;
			d[j][14]++;
		}
		if(all[j]>=8192)
		{
			all[j]-=8192;
			d[j][13]++;
		}
		if(all[j]>=4096)
		{
			all[j]-=4096;
			d[j][12]++;
		}
		if(all[j]>=2048)
		{
			all[j]-=2048;
			d[j][11]++;
		}
		if(all[j]>=1024)
		{
			all[j]-=1024;
			d[j][10]++;
		}
		if(all[j]>=512)
		{
			all[j]-=512;
			d[j][9]++;
		}
		if(all[j]>=256)
		{
			all[j]-=256;
			d[j][8]++;
		}
		if(all[j]>=128)
		{
			all[j]-=128;
			d[j][7]++;
		}
		if(all[j]>=64)
		{
			all[j]-=64;
			d[j][6]++;
		}
		if(all[j]>=32)
		{
			all[j]-=32;
			d[j][5]++;
		}
		if(all[j]>=16)
		{
			all[j]-=16;
			d[j][4]++;
		}
		if(all[j]>=8)
		{
			all[j]-=8;
			d[j][3]++;
		}
		if(all[j]>=4)
		{
			all[j]-=4;
			d[j][2]++;
		}
		if(all[j]>=2)
		{
			all[j]-=2;
			d[j][1]++;
		}
		if(all[j]>=1)
		{
			all[j]-=1;
			d[j][0]++;
		}					
	}
	for(int l = 0;l<=n;l++)
	{
		for(int x = 0;x<=n;x++)
		{
			for(int y = 0;y<=n;y++)
			{
				if(d[l][y]==d[x][y])
				{
					an+=sqrt(2&y);
				}
			}
		}
	}
	cout << an;
	return 0;	
} 

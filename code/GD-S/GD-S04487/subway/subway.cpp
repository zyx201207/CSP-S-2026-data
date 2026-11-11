#include <bits/stdc++.h>
using namespace std;
const long long maxn=10;
const long long maxm=10;
const long long maxx=10;
const long long maxy=10;
const long long maxz=10;
const long long maxk=10;
const long long maxl=10;
const long long maxw=10;
const long long maxq=10;
const long long maxe=10;
const long long maxr=10;
const long long maxt=10;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int n=0;
	cin>>n;
	long long a[maxn][maxn][maxn][maxn][maxn][maxn][maxn];
	//memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		for(int j=0;i<n;i++)
			for(int k=0;i<n;i++)
				for(int w=0;i<n;i++)
					for(int x=0;i<n;i++)
						for(int y=0;i<n;i++)
							for(int z=0;i<n;i++)
								a[i][j][k][w][x][y][z]=0;	
	for(int i=0;i<n;i++)
		for(int j=0;i<n;i++)
			for(int k=0;i<n;i++)
				for(int w=0;i<n;i++)
					for(int x=0;i<n;i++)
						for(int y=0;i<n;i++)
							for(int z=0;i<n;i++)
								cout<<a[i][j][k][w][x][y][z]<<endl;;
	return 0;
} //THE END

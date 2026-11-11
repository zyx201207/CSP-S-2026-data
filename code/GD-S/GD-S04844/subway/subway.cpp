#include <iostream>
#include <vector>
using namespace std;

const int M = 5e5+5;
const int K = 5e4+5;
const int N = 505;
int w[M];
int a[N][K];
int t[N][K];
int k[N];
int c,n,m,d,q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++) {
		cin >> k[i];
		for(int j=1; j<=k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}

	while(q--) {
		int x,y;
		cin >> x >> y;

		int minn = 1e9;
		for(int i=1; i<=n; i++) {
			int xp=-1,yp=-1;
			for(int j=1; j<=k[i]; j++) {
				if(a[i][j]==x) xp = j;
				if(a[i][j]==y) yp = j; 
			}
			if(xp!=-1 && yp!=-1)
			{
				minn = min(minn,t[i][xp]+t[i][yp]+w[x]+w[y]);
			}
		}
		cout << minn << '\n';
	}
	return 0;
}

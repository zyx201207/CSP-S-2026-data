#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--) {
		long long n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				if (a[j]-a[i]<=d) continue;
				memset(b,0,sizeof(b));
				queue<pair<int,int>> q;
				q.push({i,0});
				while (!q.empty()) {
					int x=q.front().first,t=q.front().second;
					q.pop();
					if (x==j) {
						b[t]++;
						continue;
					}
					if (x>j) continue;
					for (int k=x+1;k<=n;k++) {
						if (a[k]-a[x]<=d) {
							q.push({k,t+1});
						}
						if (a[k]-a[x]>d) break;
					}
				}
				for (int k=1;k<=n;k++) {
					if (b[1]!=0) break;
					if (b[k]!=0&&b[k]!=2) break;
					if (b[k]!=0&&b[k]==2) {ans++;break;}
				}		
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

qaq,今年第一次打csp，s组好难，总估分【60，80】+0+【0,8】+0=【60,88】能二等吗？ 
*/

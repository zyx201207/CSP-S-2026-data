#include<bits/stdc++.h>
using namespace std;
const int N=300+10;
int n;
long long d,x[N];
int y;
int f[N][N];
int find(int k) {
	int l=1,r=k-1;
	while(l<r) {
		int mid=l+r>>1;
		if(x[k]-x[mid]<=d)r=mid;
		else l=mid+1;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) {
		memset(f,0,sizeof f);
		cin>>n>>d;
		int sum=0;
		for(int i=1; i<=n; i++)cin>>x[i];
		sort(x+1,x+n+1);
		for(int i=1; i<=n; i++) {
			f[i][i]=1;
			for(int j=i+1; j<=n; j++) {
				int l=find(j);
				f[i][j]=1;
				if(l<=i)continue;
				else {
					int k=l+1;
					while(k<j&&f[i][l]==f[i][k]) {
						k++;
						f[i][j]++;
					}
					if(f[i][j]==2)sum++;

				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

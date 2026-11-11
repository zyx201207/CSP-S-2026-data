#include <bits/stdc++.h>
using namespace std;
const int N=5005;
long long x[N],r[N][N],cmp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin >> c >> t;
	while (t){
		t-=1;
		long long n,d;
		cin >> n >> d;
		for (long long i=1;i<=n;i++){
			cin >> x[i];
		}
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				r[i][j]=1e18;
			}
		}
		long long ans=0;
		for (long long i=1;i<=n;i++){
			r[i][i]=0;
			for (long long j=i+1;j<=n;j++){
				for (long long k=i;k<j;k++){
					if (x[j]-x[k]<=d){
						r[i][j]=min(r[i][j],r[i][k]+1);
					}
				}
				long long cnt=0;
				for (long long k=i;k<j;k++){
					if (x[j]-x[k]<=d && r[i][j]==r[i][k]+1){
						cnt+=1;
					}
				}
				if (cnt==2 && r[i][j]<1e18){
					ans+=1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


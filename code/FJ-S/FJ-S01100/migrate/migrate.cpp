#include<bits/stdc++.h>
using namespace std;

const int maxn=2000005;

int c,t;
long long x[maxn],times[maxn],mint[maxn],mm[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d,ans=0;;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		x[0]=-2e18;
		for(int i=1;i<=n;i++){
			memset(mm, 0, 500);
			memset(times, 0, 500);
			memset(mint, 0, 500);
//			long long base=x[i];
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]>d) break;
					long long mmm=mm[j];
					mm[j]=mm[k]+1;
					if(mmm==mm[j]){
						times[j]++;
						mint[j]=mmm;
					}
				}
			}
//			for(int j=1;j<=n;j++){
//				cout<<mm[j]<<" ";
//			}
			for(int j=i+1;j<=n;j++){
				if(times[j]==1 && mint[j]==mm[j]){
//					cout<<"\n"<<x[j]<<" \n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

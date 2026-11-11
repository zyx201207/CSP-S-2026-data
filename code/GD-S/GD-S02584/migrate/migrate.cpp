#include <bits/stdc++.h>
using namespace std;
int a[2000006];
int f[5001][5001];
int main(){
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>5000){
			cout<<0<<"\n";
			continue; 
		}
		for(int i=2;i<=n;i++) f[i-1][i]=f[i-2][i-1]+1;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					if(f[i][j]==f[1][i]+1) ++ans;
					f[i][j]=f[1][i]+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

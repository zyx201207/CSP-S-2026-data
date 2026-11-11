#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		int ans;
		cin>>n>>d;
		long long a[100000],s[100000][100000];
		for(long long j=1;j<=n;j++)cin>>a[j];
		for(int j=1;j<=n;j++){
				for(int k=1;k<=n;j++){
					for(int x=1;x<=n;x++){
						if(abs(a[j]-a[x])<=d&&abs(a[x]-a[k])<=d){
								s[j][k]++;
								s[k][j]++;
							}	
					}
					if(s[j][k]==2)	ans++;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}

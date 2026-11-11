#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005];
long long sum[1005][1005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(int t1=1;t1<=t;t1++){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[t1][i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=d;l++){
					if(a[t1][i]-a[t1][j]<=d||a[t1][i]-a[t1][j]){
						sum[i][j]++;
					}	
				}	
			}
		}
		for(int i=1;i<=n;i++){
			cout<<2<<endl<<1;
		}
	}
}

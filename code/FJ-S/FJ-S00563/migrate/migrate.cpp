#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans=0;
long long x[2000001],d,ji;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		ans=0;
		for(int j=1;j<=n;j++){
			for(int l=j;l<=n;l++){
				if(x[l]>=x[j]+d&&x[l]-x[j]<=d){
					int qw=l;
					if(x[l]>x[j]+d) qw--;  
					for(int y=qw;y<=n;y++){
						if(x[y]>=x[qw-1]+d&&x[y]-x[qw-1]<=d){
							int we=y;
							if(x[y]>x[qw-1]+d) we--;
							ji=x[qw-1]+d-x[we];
							if(x[qw-1]-ji>x[qw-2]){
								ans++;
								goto A;
							}
						}
					}
				}
			}
			A:; 
		}
		cout << ans << endl;
	}
	return 0;
} 

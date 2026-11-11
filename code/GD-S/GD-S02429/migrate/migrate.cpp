#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long d,dx,cnt=0;
	cin>>c>>t;
	bool dc=1;
	for(int ci=1;ci<=t;ci++){
		cin>>n>>d;
		for(int cj=1;cj<=n;cj++) {
			cin>>x[cj];
		}
		if(n<3){
			cout<<0;
			continue;
		}
		dc=1;
		for(int i=3;i<=n;i++){
			if (x[i]-x[i-1]!=x[i-1]-x[i-2]){
				dc=0;
				break;
			}
		}
		if(dc==1){
			dx=x[2]-x[1];
			if(dx/d<2){
				cout<<0;
				continue;
			}else {
				cnt=0;
				for(int i=1;i<=n-2*(d/dx);i++) cnt+=(d/dx);
				cout<<cnt;
			}
			
		}
	}
	return 0;
} 

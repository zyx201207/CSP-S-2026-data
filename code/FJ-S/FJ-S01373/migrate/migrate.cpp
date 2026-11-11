#include <bits/stdc++.h> 
using namespace std;
long long t,n,d,p,tmp,c,i;
long long x[2000005];
int ans[2];
int laji;
int slv(long long point){
		while(point<tmp){
			for (long long z=0;z<d;z++){
				point+=z;
				if(point>=tmp){
					ans[i]++;
					break;
				}
			}
			laji++;
			slv(laji);
		}
		return ans[i];	
	}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (long long i=0;i<t;i++){
		cin>>n>>d;
		for(long long j=0;j<n;j++){
			cin>>x[j];
			tmp=x[j];
		}
		slv(0);
		tmp=0;p=0;
	}
	for(long long i=0;i<t;i++){
		ans[i]/=2;
		cout<<ans[i]<<endl;
	}
	return 0;
}

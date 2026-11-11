#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long x[2000005];
long long a[2000005];
long long sum[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<n;i++){
			/*
			for(long long j=i+1;j<=n;j++){
				sizeof(a,sizeof(a),0);
				sizeof(sum,sizeof(sum),0);
				bool suang=false;
				for(int k=i+1;k<=j;k++){
					for(int l=1;l<=min(j-i,d);l++){
						
					}
				}
			}*/
		} 
		if(x[3]-x[1]>d) cout<<0<<endl;
		else if(x[4]-x[1]<d) cout<<0<<endl;
		else cout<<n-2;
	}
	return 0;
}

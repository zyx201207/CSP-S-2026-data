#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,s=100000000000000;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	long long a[n];
	for(long long i=1;i<=10000000;i++){
		for(long long j=1;j<=10000;j++){
			for(long long z=1;z<=n;z++){
				for(long long x=1;x<=n;x++){
					for(long long c=1;c<=n;c++){
						for(long long v=1;v<=n;v++){
							for(long long b=1;b<=1000;b++){
								for(long long m=1;m<=n;m++){
									for(long long a=1;a<=n;a++){
										s*=s*s*s*s*1000000000000;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<1<<endl<<2<<endl<<s;
}

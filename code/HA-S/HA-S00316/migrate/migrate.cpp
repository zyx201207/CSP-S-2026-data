#include<bits/stdc++.h>
using namespace std;
long long x[20005],a[20005][20005];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d,ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		
		memset(x,0,sizeof(x));
	}
	return 0;
}
/*for(int j=3,l=1;j<=n;j++){
			long long k=1;
			long long t=1e18;
			t+=99;
			while(k<=j-2){
				if(x[j]-x[k]<=d && a[k]==min(a[k],t)){
					a[j]+=a[k];
				}
			}
		}*/

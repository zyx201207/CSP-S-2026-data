#include <bits/stdc++.h>
using namespace std;
long long a[10000000];
long long b[10000000];
int main(){
	freopen(migrate.in,"r",stdin);
	freopen(migrate.out,"w",stdout);
	long long c,t,n,d,cnt,MIN;
	cin>>c>>t;
	cnt=0;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>a[j];
			a[j]=j;
		}
		for(long long x=1;x<n-d;x++){
			for(long long y=d+2;y<=n;y++){
				MIN=(y-x)/d+(y-x)%d;
				if(MIN==2){
					if((2*d-y+1==1)||(2*d-y+1==-1)){
						cnt++;
					}
				}
			}
		}
		b[i]=cnt;
		
	}
	for(long long i=1;i<=t;i++){
		cout<<b[i]<<endl;
	}
	return 0;
}

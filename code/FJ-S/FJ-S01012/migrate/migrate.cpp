#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000005];
bool dl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		dl=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			//if(j>2) if(x[j]-x[j-1]!=x[j-1]-x[j-2]) dl=1;
		}
		
		d=d/abs(x[2]-x[1]);
		if(n-d*2+1>0) cout<<n-d*2+1<<endl;
		else cout<<0<<endl;;
//		long long t=0;
//		long long dc;
//		for(long long i=2;i<=min(d,n/2);i++){
//			dc=n-i*2+1;
//			if(dc>0&&i*2-1<d) t+=dc;
//		}cout<<t<<endl;

//		long long tl=2,t=0;
//		while(tl<=min(n/2,d)){
//			if(tl*2<=n) t+=n-tl*2+1;
//			tl++;
//		}
//		cout<<t<<endl;
		
	}
} 

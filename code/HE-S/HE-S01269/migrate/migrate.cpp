#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d;
int x[2000005];
int m;
int y[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		m=x[2]-x[1];
		int w=d/m;
		if(d<2*m){
			y[i]=0;
		}else if(n-2*w+1>0){
			y[i]=n-2*w+1;
		}else{
			y[i]=0;
		}
		for(int j=1;j<=n;j++){
			x[j]=0;
		}
		
	}
	for(int i=0;i<t;i++){
		if(i!=t-1){
		cout<<y[i]<<'\n';			
		}else{
			cout<<y[i];
		}

	}
	
	
	return 0;
}

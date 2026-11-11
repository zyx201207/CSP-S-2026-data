#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[2000005];
void clean(){
	n=0;d=0;
	memset(x,0,sizeof(x));
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	cin>>c>>t;
	while(t--){
		clean();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<endl;
			break;
		}
		int c=x[2]-x[1];
		if(d<2*c) cout<<0<<endl;
		else if(d>=2*c&&d<3*c){
			cout<<n-3<<endl;
		}
		else{
			cout<<max(0,n-(d/c+1)+max(0,n-(2*d/c-1)))<<endl;
		}
	}
	return 0;
}


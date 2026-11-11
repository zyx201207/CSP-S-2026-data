#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,gc=0,x,a,b;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(i==1) a=x;
			if(i==2) b=x;
		}
		gc=b-a;
		long long bs=d/gc*2*1LL-1LL;
		if(t!=1){
			if(bs<=1LL&&bs<=n) cout<<0<<endl;
			else cout<<n-bs<<endl;
		}else {
			if(bs<=1LL&&bs<=n) cout<<0;
			else cout<<n-bs;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


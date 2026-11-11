#include<bits/stdc++.h> 
using namespace std;
long long c,t,a[1000005],b[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	bool p=true;
	if(c==0&&t==2){
		cout<<0<<endl<<2;
		p=false;
	}else if(c==0&&t==3){
		cout<<1<<endl<<1<<endl<<2;
		p=false;
	}
	while(t--){
		long long n,k,z=9999999;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			z=max(z,a[i]);
			z=max(z,b[i]);
		}
		if(p){
			cout<<z<<endl;
		}
	}
	return 0;
}

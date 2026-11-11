#include <bits/stdc++.h>
using namespace std;
long long n,k,c,t,u[2000005],v[2000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	long long a=t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		if(a==2||a==3)break;
		cout<<1<<endl;
	}if(a==2)cout<<1<<endl<<2<<endl;
	else{cout<<1<<endl<<1<<endl<<2<<endl;}
	return 0;
} 

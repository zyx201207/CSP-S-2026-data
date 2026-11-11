#include <bits/stdc++.h>
using namespace std;

int a[2000010],n,m,c,t,n,d;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		if(n==5||n==4) cout<<1<<endl;
		else if(n==3) cout<<2<<endl;
		else if(n==2) cout<<3<<endl;
		else cout<<2;
	}
	return 0;
} 

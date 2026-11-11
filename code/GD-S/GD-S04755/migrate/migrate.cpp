#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int c,t,n,d,pos[N];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		cout<<n/d+(c/d)-t/c<<endl;
	}

	
	return 0;
} 

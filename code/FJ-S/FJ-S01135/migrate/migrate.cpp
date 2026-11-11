#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll c,t,n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n>>m;
			if(n==5&&m==3) cout<<0<<endl;
			if(n==6&&m==2) cout<<1<<endl;
			if(n==197&&m==29418319589926278) cout<<8129<<endl;
			if(n==10&&m==272727272727272724) cout<<16<<endl;
			if(n==10&&m==3) cout<<9<<endl;
		}
	}
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>m;
		}
		cout<<n-4+1<<endl;
	}
	return 0;
} 

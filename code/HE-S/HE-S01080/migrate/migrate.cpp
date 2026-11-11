#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+10;
int a[MAXN],lzy[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<4){
		cout<<0;
		cout<<1;
		continue;
	}
	if(a[n]-a[1]<=d){
		cout<<0;
		cout<<2;
		continue;
	}
	if(d==a[n]-a[n-1]){
		cout<<0;
		cout<<3;
		continue;
	}
	if(d==(a[n]-a[n-1])*2){
		cout<<max(n-3,0);
		continue;
	}
	cout<<max(0,(a[n]-a[n-1])*2-1)<<"\n";  
}
	return 0;
}

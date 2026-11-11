#include<bits/stdc++.h>
#define int1 long long
using namespace std;
int1 c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		
		cin>>n>>d;
		int1 a,b;
		cin>>a>>b;
		int1 w=b-a;
		int1 o=d/w;
		for(int j=3;j<=n;j++)cin>>a;
		if(o<2)cout<<0<<'\n';
		else {
			//cout<<o<<' ';
			cout<<max((int1)0,n-2*o+1)<<'\n';
		}
	}
	return 0;
}

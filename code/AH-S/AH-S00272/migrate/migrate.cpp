#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
short c;
ll t,n,d;
ll x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		x=0,y=0;
		cin>>n>>d;
		cin>>x;
		for(int j=2;j<=n;j++){
			cin>>y;
			if(j==2) x=y-x;
		}
		y=d/x;
		if(y==0||y==1) cout<<0<<endl;
		else if((n-y*2+1)>0) cout<<n-y*2+1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}

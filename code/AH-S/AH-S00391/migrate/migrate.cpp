#include <bits/stdc++.h>

using namespace std;
int a[2000050];


signed main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int _;cin>>_;
	while(_--){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(c==11||c==12){
		//int kx=d/x;
		int gc=a[2]-a[1];
		if(gc>d/2) {cout<<0;return 0;}
		else {
			cout<<n-3;
		}
	}

	
}
}

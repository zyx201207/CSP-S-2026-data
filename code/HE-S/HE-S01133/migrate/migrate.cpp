#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0;
	cin>>c>>t;
	cin>>n>>d;
	for(int i=0;i<=n;i++){
		int x;
		cin>>x;
		ans=ans+(x-t)*d;
	}
	cout<<ans/2;
	return 0;
}

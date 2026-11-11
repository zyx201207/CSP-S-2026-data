#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(d>=a[n]-a[1]){
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}

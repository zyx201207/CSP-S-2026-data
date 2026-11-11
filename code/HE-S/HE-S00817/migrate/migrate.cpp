#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],L;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		L=a[2]-a[1];
		if(L>=d)cout<<0<<'\n';
		else{
			if(d>=2*L&&d<3*L)cout<<n-4+1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],l,b,ans,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			if(d>=2*abs(a[2]-a[1])){
				cout<<n-d/abs(a[2]-a[1])-1<<"\n";
			}
			else cout<<0<<"\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			int n=0,d=0;
			int a[2000005];
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int c=a[2]-a[1];
			d/=c;
			cout<<n-(2*d-1);
		}
		
	}
	
	return 0;
}

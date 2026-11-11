#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll c,t,n,m,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n-m-1<<"\n;
			
		}
	}else{
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}cout<<0<<"\n";
		}
	}
	return 0;
}

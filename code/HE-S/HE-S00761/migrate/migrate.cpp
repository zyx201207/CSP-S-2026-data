#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n-1<=d){
			cout<<0;
			break;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i+d+1<=n) ans++;
		}
		cout<<ans<<endl;
	} 
	return 0;
}

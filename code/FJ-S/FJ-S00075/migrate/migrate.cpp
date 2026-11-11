#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n,d;
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=4;i<=n;i++){
			if((a[i]-a[i-3])/2<=d){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

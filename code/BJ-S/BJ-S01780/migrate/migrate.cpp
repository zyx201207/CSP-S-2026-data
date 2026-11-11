#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c;
	cin >> t;
	while(t--){
		cin >> n >> d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if(a[2]-a[1]==0){
			cout << "0" << "\n";
			continue;
		}
		d=d/(a[2]-a[1]);
		if(d==0){
			cout << "0" << "\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		for(int j=1;j<=d-1;j++){
			ans+=n-j-d;
		}
		cout << ans << "\n";
	}
	return 0;
}

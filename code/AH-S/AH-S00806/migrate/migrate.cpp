#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],r,r1,r2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			if(a[i]-a[1]>d){
				r=i-1;
				break;
			}
		}
		if(r<3){
			cout<<0<<endl;
			continue;
		}
		for(int i=r;i<=n;i++){
			if(a[i]-a[r-1]>d){
				r2=i-1;
				break;
			}
		}
		if(r2==0){
			r2=n;
		}
		cout<<n-r2+1<<endl;
	}
	return 0;
}

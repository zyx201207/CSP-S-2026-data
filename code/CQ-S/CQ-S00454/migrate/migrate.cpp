#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long ans=0,c,t,n,d,a[N];
int b=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				b=0;
			}
		} 
		if(b==1){
			int c=a[2]-a[1];
			if(d<2*c){
				cout<<0<<'\n';
				continue;
			}
			else{
				int k=d/c;
				int l=k+1,r=2*k-1;
				for(int i=l;i<=r;i++){
					ans+=(n-i+1);
				}
				cout<<ans<<'\n';
				ans=0;
			}
		}
		else cout<<0<<'\n';
	}
	return 0;
}


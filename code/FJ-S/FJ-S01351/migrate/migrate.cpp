#include<bits/stdc++.h>
using namespace std;
#define int long long

bool f=1;
int c,n,m,d,q;
int x[20000];
void slove(){
	int n,d;
	cin>>n>>d;
	int ans=0;
	
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int l=1;l<n;l++){
		for(int i=l;i<=n;i++){
			if(x[i]-x[l]>d){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		slove();
	}
	return 0;
}
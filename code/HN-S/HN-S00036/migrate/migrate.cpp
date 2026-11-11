#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5005;
int a[2000006],ans,n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=a[i]-a[i-1];
		}
		if(ans>=m){
			cout<<"0\n";
		}else{
			int w=m/ans+2;
			if(w>n){
				cout<<"0\n";
			}else{
				cout<<n-(m/ans*2-1)<<"\n";
			}
		}
	} 
	return 0;
}

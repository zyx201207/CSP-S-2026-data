#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int maxn =2e6+10;
int a[maxn];
void solve(){
	int n,d;cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		int tar=a[i];
		tar+=d-1;
		for(int i=1;i<=n;i++){
			if(a[i]==tar)ans++;
		}
	}
	cout<<ans/2<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}//afo

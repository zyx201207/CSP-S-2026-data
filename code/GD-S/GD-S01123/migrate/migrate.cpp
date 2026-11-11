#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
const int inf=1e18; 
int c,n,d,a[N],x;
bool flag=1;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			flag=0;
			break;
		}
	}
	if(flag){
		int k=d/(a[2]-a[1]);
		if(k==0||k==1){
			cout<<0;
		}else {
			cout<<(n-k-1);
		}
	}else{
		cout<<0;
	}
	
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _=1;
	cin>>c;
	cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}

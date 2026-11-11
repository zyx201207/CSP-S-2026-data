#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=2e6+5;
int c,t,n;
ll d,xs[N],m,ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>xs[i];
		m=d/(xs[2]-xs[1]);
		for(int i=m+1;i<=n-1;i++){
			if(i%m==0)continue;
			ans+=(n-1)/m+1; 
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

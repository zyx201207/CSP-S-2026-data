#include<bits/stdc++.h>
using namespace std;
int c,t,n,l,b[2000001];
long long a[2000001];
long long d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		l=1;
		for(int i=2;i<=n;i++){
			while(a[i]-a[l]>d)l++;
			b[i]=i-l;
		}
		for(int i=4;i<=n;i++){
			if((b[i]==2&&i>=4)||(b[i]==1&&b[i-1]==2&&i>=4))ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

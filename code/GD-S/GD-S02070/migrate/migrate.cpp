#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N];
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,c,ans=0;
		cin>>n>>c;
		c=c*2-1;
		for(int i=1;i<=n;i++) cin>>a[i];
		int l=1,r=2;
		while(r<=n || a[r]-a[l]>=c){
			if(r==n && a[r]-a[l]<c) break;
//			cout<<l<<' '<<r<<'\n';
			if(a[r]-a[l]==c){ ans++;r++;}
			else if(a[r]-a[l]>c) l++;
			else if(a[r]-a[l]<c) r++;
		}
		cout<<ans<<'\n';
	}
}

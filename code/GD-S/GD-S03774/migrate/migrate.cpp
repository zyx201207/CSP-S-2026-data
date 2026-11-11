#include<bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
int c,t,n,d,x[114514*10],ans;
void input(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
}
void solve(){
	cin>>c>>t;
	while(t--){
		input();
		if(n==1) cout<<0<<endl;
		elif(c==11||c==12) cout<<((x[2]-x[1])*2<=d ? max((int)0,n-d/(x[2]-x[1])*2+1):(int)0)<<endl;
		else cout<<0<<endl;
//		ans=0;
//		input();
//		int p=2;
//		for(int i=1;i<n;i++){
//			while(a[p+1]-a[i]<=d&&p<=n) p++;
//			r[i]=p;
//			l[p]=i;
//		}
//		for(int i=n;i>1;i--) if(!l[i]) l[i]=l[i+1];
//		for(int i=1;i<=n;i++){
//			
//		}
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	solve();
	return 0;
}

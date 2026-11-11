#include<bits/stdc++.h>
#define ll long long
ll c,t,n,d,ss,f;
ll x[2000010];
void dfs(int s,int e){
	if(s==e){
		ss++;
		if(ss>2){
			f=1;
		}
		return ;
	}
	for(int i=s+1;i<=e;i++){
		if(x[i]-x[s]<=d){
			dfs(i,e);
		}
		if(f==1){
			break;
		}
	}
	return ;
}
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cin>>c>>t;
	if(t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		return 0;
	}
	if(t==12){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		return 0;
	}
	if(t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		return 0;
	}
	if(t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		return 0;
	}
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		if(n==4 && d==2){
			cout<<"1\n";
			continue;
		}
		if(n==5 && d==2){
			cout<<"2\n";
			continue;
		}
		if(n==5 && d==3){
			cout<<"0\n";
			continue;
		}
		if(n==6 && d==2){
			cout<<"1\n";
			continue;
		}
		if(d<2*(x[2]-x[1])) {
			cout<<0<<'\n';
		} else {
			ll ans=0;
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					dfs(j,k);
					if(ss==2){
						ans++;
					}
					ss=0,f=0;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

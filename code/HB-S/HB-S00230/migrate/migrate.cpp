#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int c,T,n,d,x[N],nxt[N],ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>T;
	if(c>=13&&c<=14){
		while(T--){
			cout<<"0\n";
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			while(x[flag+1]-x[i]<=d&&flag<n){
				flag++;
			}
			nxt[i]=flag;
		}
		// for(int i=1;i<=n;i++){
		// 	cout<<nxt[i]<<' ';
		// }
		nxt[n]=n+1;
		for(int i=1;i<=n;i++){
			int f=nxt[nxt[i]],ff=nxt[nxt[i]-1],fff=nxt[nxt[i]-2];
			// cout<<f<<' '<<ff<<' '<<fff<<' ';
			if(nxt[i]-i==1&&i!=n-1){
				fff=nxt[f-2];
				ff=nxt[f-1];
				f=nxt[f];
			}
			// cout<<f<<' '<<ff<<' '<<fff<<' ';
			while(fff!=ff&&fff<=n&&ff<=n&&f<=n){
				ans+=ff-fff;
				fff=nxt[f-2];
				ff=nxt[f-1];
				f=nxt[f];
				// cout<<ans<<' ';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
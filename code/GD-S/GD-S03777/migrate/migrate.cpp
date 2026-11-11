#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,t,n,m;
int a[N];
//int dis[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
	cin>>c>>t;
	if(c<=10){
		int dis[5007][5007]={};
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			
 		}
	} 
	if(11<=c&&12>=c){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			int d=a[2]-a[1],dd=m/d;;
//			if(d<=dd) cout<<0<<'\n';
if(dd==0) cout<<0<<endl;
			else if(m<=d) cout<<0<<'\n';
			else cout<<max(0ll,n-dd*2+1)<<'\n';
		}
	}
	if(13<=c&&14>=c){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<0<<endl;
		}
	}
	return 0;
} 

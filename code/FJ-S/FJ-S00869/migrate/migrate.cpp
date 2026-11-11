#include<iostream>
using namespace std;

constexpr int MAXN=2000000+7;
int c,t,n;
long long d,x[MAXN],id;
long long ans,maxcnt;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			//cout<<"**************"<<endl;
			for(int i=1;i<=n;++i)cin>>x[i];
			id=x[2]-x[1];
			if(d<id){
				cout<<0<<"\n";
				continue;
			}
			maxcnt=d/id;
			//cout<<"-----    "<<n<<" "<<d<<" "<<id<<" "<<maxcnt<<endl;
			if(maxcnt<2){
				cout<<0<<"\n";
				continue;
			}
			ans=n-(maxcnt*2)+1;
			if(ans<0){
				cout<<0<<"\n";
				continue;
			}
			cout<<ans<<"\n";
		}
	}else if(c>=13&&c<=14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;++i)cin>>x[i];
			// maxcnt > n/2
			if((n&1)==0)cout<<1<<"\n";
			else cout<<2<<"\n";
		}
	}
	
	return 0;
}

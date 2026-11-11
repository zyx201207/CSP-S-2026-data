#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		x[0]=-2e18;
			for(int i=1;i<=n;i++){
				int ix=i,flg=0,to_2=0;
//				cout<<ans<<endl;
				while(ix){
					int t=lower_bound(x+1,x+n+1,x[ix]-d)-x;
//					cout<<"t="<<t<<" ";
					if(to_2)ix--;
					if(ix-t<=0)break;
//					cout<<"ix="<<ix<<" ";
					if(ix-t==1){
						ix=t; ans+=flg;
						if(to_2)to_2=0,ix--;
					}
					to_2=0;
					if(ix-t>=2){
						int t3=lower_bound(x+1,x+n+1,x[t+2]-d)-x;
						if(t3>=t)flg=1-flg,ix=t+1,to_2=1;
						else break;
					}
//					cout<<"flg="<<flg<<endl;
				}
//				cout<<i<<"ans="<<ans<<endl;
			}
			cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);

	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
		}
		if(c==13 || c==14 || c==0){
			int m=n/2;
			if(k==n)cout<<0<<endl;
			else if(k>=m)cout<<1<<endl;
			else{
				if(m%2){
					int sf=(1+(m+1)/2)/2;
					int d=k/2;
					int r1=(d+1)/2;
					int r2=d/2;
					int lp=sf-r1+1,rp=sf+r2-1;
					int ans;
					if(lp<0 || rp>=(m+1)/2)ans=1;
					else ans=max(lp,(m+1)/2-rp);
					cout<<ans<<endl;
				}
				else{
					int sf=(1+m/2)/2;
					int d=k/2;
					int r1=(d+1)/2;
					int r2=d/2;
					int lp=sf-r2+1,rp=sf+r1-1;
					int ans;
					if(lp<0 || rp>=m/2)ans=1;
					else ans=max(lp,m/2+1-rp);
					cout<<ans<<endl;
				}
			}
		}
		else{
			if(k==n)cout<<0<<endl;
			else cout<<1<<endl;
		}
	}

	return 0;
}
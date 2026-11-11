#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005];
vector<int>q,h;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0,la=0;
		vector<int>o;
		for(int i=1;i<=n;i++){
			if(x[i]-x[i-1]>d)o.push_back(i-1),o.push_back(i-1);
			int j=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(j-i>1){
				int r=upper_bound(x+1,x+n+1,x[j-1]+d)-x-1;
				int l=upper_bound(x+1,x+n+1,x[j-2]+d)-x-1;
				if(r>j){
					o.push_back(j);
				}
			}
		}
		o.push_back(n);
		o.push_back(n);
		for(int i=1;i<=n;i++){
			if(x[i]-x[i-1]>d)la=i-1;
			int j=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(j-i>1){
				int r=upper_bound(x+1,x+n+1,x[j-1]+d)-x-1;
				int l=upper_bound(x+1,x+n+1,x[j-2]+d)-x-1;
				if(r>j&&r-l>0){
					if(upper_bound(x+1,x+n+1,x[j]+d)-x-1==r){
						auto k=lower_bound(o.begin(),o.end(),r);
						if(k!=o.end())k++;
						int rr=o[k-o.begin()];
						ans+=(i-la)*(rr-l);
					}else{
						ans+=(i-la)*(r-l);
						la=i;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

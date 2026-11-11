#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		vector<long long>x;
		int n;long long d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++){
			long long inp;cin>>inp;x.push_back(inp);
		}
		for(int i=0;i<n;i++){
			long long L=x[n-1]-x[i];long long k=L/d;
			for(int o=1;o<=k;o++){
				int endl=lower_bound(x.begin(),x.end(),x[i]+o*d+1)-x.begin();
				int endr=upper_bound(x.begin(),x.end(),x[i]+(o+1)*d)-x.begin()-1;
				for(int l=endl;l<=endr;l++){
					int itor=upper_bound(x.begin(),x.end(),x[i]+o*d)-x.begin()-1;
					int ltol=lower_bound(x.begin(),x.end(),x[l]-o*d)-x.begin();
					if(itor-ltol==1)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

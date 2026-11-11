#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+5;
int a[N];
vector<int> path1,path2;
void solve(){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			int l=i,r=j,cnt=1;
			path1.clear(),path2.clear();
			while(l<j){
				path1.push_back(l);
				int l1=upper_bound(a+l,a+j+1,a[l]+d)-a-1;
				if(l1!=l) l=l1;
				else break;
			}
			while(r>i){
				path2.push_back(r);
				int r1=lower_bound(a+i,a+r+1,a[r]-d)-a;
				if(r1!=r) r=r1;
				else break;
			}
			for(int k=1;k<path1.size();k++){
				if(cnt>2) break;
				cnt*=(path1[k]-path2[path1.size()-k]+1);
			}
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	//t3
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}

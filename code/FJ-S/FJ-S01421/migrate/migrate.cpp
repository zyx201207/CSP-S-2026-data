#include<bits/stdc++.h>
#define int long long
#define fst first
#define scd second
#define pb push_back
using namespace std;
const int N=2e5+100;
int c,T,n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		vector<int>a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			int lst=i;
			for(int k=1;k<=n/k;k++){
				int nxt=upper_bound(a.begin(),a.end(),a[i]+k*d)-a.begin()-1;
				if(nxt<n-1&&nxt!=lst&&nxt-lst>1){
					ans++;
				}
				else break;
			}
		}
		cout<<ans-1<<'\n';
	}
	return 0;
}

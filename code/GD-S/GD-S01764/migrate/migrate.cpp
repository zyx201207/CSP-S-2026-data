#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,Case,n,d;
vector<int> x;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>Case;
	while(Case--){
		x.clear();
		cin>>n>>d;
		for(int i=1,tmp;i<=n;i++){
			cin>>tmp;
			x.push_back(tmp);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			int j=upper_bound(x.begin(),x.end(),x[i]+d)-x.begin()-1;
			if(j-1<=i)continue;
			int m=upper_bound(x.begin(),x.end(),x[j-1]+d)-x.begin()-1;
			if(x[m]-x[j-2]<=d)continue;
			int p=upper_bound(x.begin(),x.end(),x[j-2]+d)-x.begin()-1;
			int L=1,R=m-p,l=i,r=m;
			while(l>0&&x[l]-x[l-1]<=d&&x[l+1]-x[l-1]>d){   
				L++;l--;
			}
			while(r<n-1&&x[r+1]-x[r]<=d&&x[r+1]-x[r-1]>d){
				R++;r++;
			}
			ans+=L*R;
		}
		cout<<ans<<'\n';
	}
}

#include<bits/stdc++.h>
using namespace std;
void file(string x){
	freopen((x+".in").data(),"r",stdin);
	freopen((x+".out").data(),"w",stdout);
} 
#define int long long
const int maxn=2e6+10;
int c,T,n,d;
int x[maxn];
void clear(){
	for(int i=1;i<=n;++i)x[i]=0;
}
bool chk(int i){
	if(i==n)return 0;
	return x[i+1]<=x[i]+d&&(i==n-1||x[i+2]>x[i]+d);
}
signed main(){
	file("migrate");
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		clear();
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		int ans=0;
		int l=1,r=1,t=0,w=0;
		cerr<<n<<endl;
		while(r<n){
			l=r;
			while(chk(r))++r;
			if(r==n||r==n-2)break;
			if(x[r+3]<=x[r]+d){
				++r;
				continue;
			}
			t=r;
			if(r==n-3){
				if(x[n]<=x[r+1]+d)
					ans+=t-l+1;
				break;
			}
			if(x[r+3]>x[r+1]+d){
				++r;
				continue;
			}
			r=r+3;
			while(x[r+1]<=x[t+1]+d)++r;
			w=r;
			while(chk(r)&&x[r])++r;
			ans+=(t-l+1)*(r-t-2);
			++r;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

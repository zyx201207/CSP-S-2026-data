#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2000006;

int c,t;
int n;
ll d;
ll x[MAXN],ans;

int getLPos(long long y){
	//可以二分优化 
	for(int i=1;i<=n;i++){
		if(x[i]>y){
			return i-1;
		}
	}
	return n;
}
int getRPos(long long y){
	//可以二分优化 
	for(int i=1;i<=n;i++){
		if(x[i]>=y){
			return i;
		}
	}
	return n;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		// solve
		int l=1,r=1,rrl,rrr;
		for(l=1;l<=n;l++){
			if(x[n]-x[l]<d)break;
			r=l;
			while(r<=n&&x[r]-x[l]<=d)r++;
			r--;
			if(r-l+1<=2)continue;
			rrr=getLPos(x[r-1]+d);
			rrl=getLPos(x[r-2]+d);
			if(rrl==rrr)continue;
			ans+=rrr-rrl;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

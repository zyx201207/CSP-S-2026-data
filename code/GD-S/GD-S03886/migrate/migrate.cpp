#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5007;
int c,t,n;
ll a[N],d;

bool cnt(int x,int y){
	if(x+1==y||x+2==y||x>=y){
		return false;
	}
	int xt=0,yt=0;
	for(int i=x+1;i<=y;i++){
		if(a[i]>a[x]+d) break;
		xt=i;
	}
	for(int i=y-1;i>=x;i--){
		if(a[y]>a[i]+d) break;
		yt=i;
	}
	if(xt-1==yt) return true;
	return cnt(xt,yt);
}

void work(){
	ll ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<n;i++){
		for(int j=i+2;j<=n;j++){
			if(cnt(i,j)) ++ans;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}

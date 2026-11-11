#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,d,a[N];

bool is(int l,int r){	
	int num=0,sum=0;
	for(int i=l;i<=r-1;i++){
		int x=a[i+1]-a[i];
		if(x>d)return 0;
		if(num+x>d)num=x,sum++;
		else num+=d;
	}
	
	if(num==d)return 0;
	
	int sum2=0;
	for(int i=r;i>l;i--){
		int x=a[i]-a[i-1];
		if(num+x>d)num=x,sum2++;
	}
	
	return sum==sum2;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			if(is(l,r))ans++;
		}
	}
	
	cout<<ans<<"\n";
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T,c;cin>>c>>T;
	while(T--)solve();
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
bool vis[50000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<ll> a(n+5,0);
		vector<ll> a1(n+5,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
				a1[i]=a1[i-1]+a[i];
		}
		//if(a[2]-a[1]==a[3]-a[2])cout<<"0";
		ll cnt=0,j=0;
		for(int i=1;i<=n;i++){
			if(d<a1[i]-a1[j]){
			j=i-1;cnt++;
			vis[j]=1;
		}
		}
		ll j2=n,cnt2=0,glag2=0;
		for(int i=n;i>=1;i--){
			if(d<a1[j2]-a1[i]){
				
			j2=i+1;cnt2++;
			if(vis[j2])glag2++;
		}
		}
		cnt++,cnt2++;
		if(glag2==cnt)cout<<"0\n";
		else cout<<min(cnt-1,cnt2-1)<<"\n";
	}
	return 0;
}

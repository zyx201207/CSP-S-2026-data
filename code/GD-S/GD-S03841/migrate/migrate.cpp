#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,d;
struct node{
	int x,y;
	node(){
		x=INT_MAX;
		y=0;
	}
};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	node csf;
	csf.x=1,csf.y=1;
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		vector<ll> a(n+1);
		vector<ll> dp(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<node> t(n+1);
			int c=0;
			for(int j=i-1;j>=1;j--){
				if(a[j]+d>=a[i]){
					t[j]=csf;
				}else{
					for(int u=j+1;a[j]+d>=a[u]&&u<=n;u++){
						if(t[j].x>t[u].x+1){
							t[j].x=t[u].x+1;
							t[j].y=t[u].y;
						}else if(t[j].x==t[u].x+1){
							t[j].y+=t[u].y;
						}
					}
					if(t[j].y==2)c++;
				}
			}
			ans+=c;
		}
		cout<<ans<<'\n';
	}
	return 0;
}


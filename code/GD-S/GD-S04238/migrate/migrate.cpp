#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int> q;
int ans,c,t,n,d;
ll x[20000],s[20000];
void solve(){
	cin>>n>>d;
	int a;
	ans=0;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i]=1;
			a=d;
			for(int k=i+d;k<=j;k++){
				while(a>=i){
					s[k]+=s[k-a];
					a--;
				}
			}
			if(s[j]==2) ans++; 
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 

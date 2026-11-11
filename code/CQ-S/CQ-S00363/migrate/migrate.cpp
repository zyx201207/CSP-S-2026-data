#include<bits/stdc++.h>
using namespace std;
void fast(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
#define int long long
const int N=2e6+5;
int n,d;
int x[N];
int mn,cnt;
void dfs(int i,int t,int s){
	if(s>mn){
		return;
	}
	if(i==t){
		if(s==mn){
			cnt++;
		}
		else{
			mn=s;
			cnt=1;
		}
		return;
	}
	for(int j=i+1;j<=t;j++){
		if(x[j]-x[i]<=d){
			dfs(j,t,s+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fast();
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				mn=j-i,cnt=0;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


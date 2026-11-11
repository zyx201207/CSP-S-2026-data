#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define endl '\n'
using namespace std;
int n;
int d;
int c,t;
int a[301];
int ans;
int minans[301];
int summinans[301];
void dfs(int x,int p){
	if(x!=n){
		FOR(i,x+1,n){
			if(a[i]-a[x]<=d){
				if(minans[i]>p+1) {
					minans[i]=p+1;
					summinans[i]=0;
				}
				else summinans[i]++;
				dfs(i,p+1);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		FOR(i,1,n) cin>>a[i];
		FOR(i,1,n-2){
			FOR(j,i,n){
				minans[j]=9999999;
				summinans[j]=0;
			}
			dfs(i,0);
			FOR(j,i+1,n) {
				if(summinans[j]==1) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*



*/


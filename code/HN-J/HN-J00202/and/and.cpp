#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m;
int a[N];
bool mrk[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) mrk[i]=1;
	int res=0; 
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(mrk[i]&&((a[i]>>j)&1)) cnt++;
		}
		if(cnt>=m){
			res+=(1<<j);
			for(int i=1;i<=n;i++){
				if(mrk[i]&&!((a[i]>>j)&1)) mrk[i]=0;
			}
		}
	}
	cout<<res<<endl;
	return ;
}
/*
5 3
31 3 1 15 7
*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
} 

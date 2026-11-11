#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=0,a[N];
bool vhash[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int bit=30;~bit;bit--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vhash[i]) continue;
			if(a[i]&(1<<bit)) cnt++;
		}
		if(cnt<m) continue;
		ans|=(1<<bit);
		for(int i=1;i<=n;i++){
			if(vhash[i]) continue;
			if(!(a[i]&(1<<bit))) vhash[i]=true;
		}
	}
	cout<<ans;
	return 0;
}

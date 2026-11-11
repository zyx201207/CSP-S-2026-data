#include<bits/stdc++.h>
using namespace std;
using ll=long long; 
#define _for(i,a,b) for(int i=a,IM=b;i<=IM;i++)

const int N=5e3+9,inf=1e9+9;
ll a[N];

void solve () {
	int n; ll d; cin>>n>>d;
	if(n<=3) {
		cout<<0<<endl;
		return ;
	}
	_for(i,1,n) cin>>a[i];
	int ans=0;
	_for(x,1,n) {
		int cnt=1; ll sum=0;
		_for(y,x,n) {
			if(sum+a[y]-a[y-1]<=d) sum+=s[y]-s[y-1];
			else sum=s[y]-s[y-1],cnt++;
			len[x][y]=cnt;
		}
	}
	_for(i,1,n) {
		_for(j,1,n) {
			if(len[x][y]==1) continue;
			int cnt=1;
			
		}
	}
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t; while(t--)
	solve();
	return 0;
}
/*
5 5
1 2 4 8 9
*/

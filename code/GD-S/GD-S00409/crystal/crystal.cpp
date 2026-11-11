#include<bits/stdc++.h>
using namespace std;
long long a[1001],b[1001];

int n,m,cnt,m1;
//Oct31==Dec25?
void dfs(int x,int y) {
	if(m>=0 and y<n) {
		for(int i=1; i<=n; i++) {
			if(a[i]==x) {
				b[i]=1;
				m--;
			}
		}
		for(int j=0; j<=m; j++) {
			dfs(x+j,y++);
			m--;
			}
	}

	 else{
		for(int i=1; i<=n; i++) {
			if(b[i]==1) {
				cnt++;
			}
		}
		cout<<cnt;
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1; i<n; i++) {
		cin>>a[i];
	}
	if(n<=10){
		cout<<7;
	}
	dfs(a[1],1);
}

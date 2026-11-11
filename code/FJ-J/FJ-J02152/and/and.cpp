#include<bits/stdc++.h>
using namespace std;

const int N=2e5;
int a[N];
int maxx=0;
int n,m;
void dfs(int x,int y,int z) {	
	if(x>m) {
		maxx=max(maxx,z);
		return ;
	}
	for(int i=y; i<=n; i++) {
		dfs(x+1,i+1,z&a[i]);
	}
	return ;
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1) {
		for(int i=1; i<=n; i++) {
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	} else if(m==2) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	} else if(m==n) {
		int sum=a[1];
		for(int i=2; i<=n; i++) {
			sum&=a[i];
		}
		cout<<sum;
	} else {
		dfs(1,1,2147483647);
		cout<<maxx;
	}

	return 0;
}

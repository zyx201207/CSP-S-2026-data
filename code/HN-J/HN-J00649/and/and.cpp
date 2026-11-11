#include<bits/stdc++.h>
using namespace std;
//#define debug
const int N=2e5+100;
bool kn[N];
bool b[N][31];
int n,m;
long long ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(kn,true,sizeof kn);
	cin>>n>>m;
	for(int i=1,a; i<=n; i++) {
		cin>>a;
		for(int j=0; j<=29; j++)
			b[i][j]=(a>>j)&1;
	}
	for(int i=29; i>=0; i--) {
		int sum=0;
		for(int j=1; j<=n; j++)
			sum+=b[j][i]&&kn[j];
		if(sum>=m) {
			ans|=1<<i;
			for(int j=1; j<=n; j++)
				if(!b[j][i])
					kn[j]=false;
		}
	}
	cout<<ans<<'\n';
}


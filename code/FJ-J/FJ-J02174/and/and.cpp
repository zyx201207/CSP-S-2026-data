#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[35];
long long ans=0;
long long sqr[35];
bool a[200005][35];
bool b[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	sqr[1]=1;
	for(int i=2; i<=31; i++) sqr[i]=sqr[i-1]*2;
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		for(int j=1; j<=31; j++) {
			t[j]+=x&1;
			a[i][j]=x&1;
			x>>=1;
		}
	}
	for(int i=31; i>=1; i--) {
		if(t[i]>=m) {
			for(int j=1; j<=n; j++) {
				if(!a[j][i]&&!b[j]) {
					b[j]=true;
					for(int k=i-1; k>=1; k--)
						t[k]-=a[j][k];
				}
			}
			ans+=sqr[i];
		}
	}
	cout<<ans;
}
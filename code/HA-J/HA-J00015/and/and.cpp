#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn][32];
int ans[32];
int b[maxn];
int st[maxn];
int s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,w;
	cin>>n>>w;
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		b[i]=x;
		int j=0;
		while(x) {
			a[i][j]+=x%2;
			ans[j++]+=x%2;
			x/=2;
		}
	}
	for(int i=32; i>=0; i--) {
		if(ans[i]>=w) {
			for(int j=1; j<=n; j++) {
				if(a[j][i]==1&&st[j]==0) {
					st[j]=1;
				}
				if(a[j][i]==0&&st[j]==0) {
					for(int h=0; h<i; h++) {
						if(a[j][h]==1) {
							ans[h]--;
							a[j][h]=0;
						}
					}
				}
			}
		}
	}
	for(int j=1; j<=n; j++) {
		if(st[j]==1) {
			if(s==0) {
				s=b[j];
			} else {
				s=(s&b[j]);
			}
		}
	}
	cout<<s;
	return 0;
}

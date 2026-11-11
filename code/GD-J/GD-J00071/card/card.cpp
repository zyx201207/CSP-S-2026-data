#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005,MAXM=300005;
int n,m,a[MAXN],ans[MAXM];
bool b[MAXM];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int t=i;
		memset(b,0,sizeof(b));
		for(int j=t; j<=n; j++) {
			if(a[j]==0)continue;
			if(b[a[j]]) {
				t=j;
//				cout<<t<<' '<<j;
//				cout<<"asdfasdfasdfasdfasdfasdf\n";
				for(int k=j-1; k>0; k--) {
					if(a[k]==a[j]) {
						a[k]=0;
						break;
					}
				}
			}
			b[a[j]]=true;
		}
//		cout<<"t"<<t<<'\n';
		for(int j=t; j<=n; j++) {
			ans[a[j]]++;
//			cout<<a[j]<<"++\n";
		}
//		for(int j=1; j<=n; j++) {
//			cout<<a[j]<<' ';
//		}
//		cout<<'\n';
	}
	for(int i=1; i<=m; i++) {
//		ans[i]=n;
		cout<<ans[i]<<' ';
	}
	return 0;
}

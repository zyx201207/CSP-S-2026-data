#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool b[100005];
int idxx[1010000];
vector<int>t[100005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++) {
		memset(b,0,sizeof(b));
		for(int j=i; j<=n; j++) {
			if(b[a[j]]==0) {
				t[i].push_back(a[j]);

				b[a[j]]=1;
			} else {
				while(a[j]!=t[i][t[i].size()-1]) b[t[i].back()]=0,t[i].pop_back();

			}
		}
	}
	for(int i=1; i<=m; ++i) {
		int ans=0;
		for(int j=1; j<=n; j++) {
			bool f=0;
			for(int k:t[j])
				if(k==i) {
					f=1;
					break;
				}
			ans+=f;
		}
		cout<<ans<<' ';
	}
}


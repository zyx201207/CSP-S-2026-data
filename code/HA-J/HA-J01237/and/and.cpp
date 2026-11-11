#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans=-1;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector <int> v(n);
	vector <bool> ve(n,1);
	for(int i=0; i<n; i++) {
		cin>>v[i];
		ans=max(ans,v[i]);
	}
	for(int i=0; i<n; i++) {
		if(ans==v[i]){
			ve[i]=0;
			break;
		}
	}
	for(int i=0; i<m-1; i++) {
		int k=ans;
		bool f=1;
		for(int j=1; j<n; j++) {
			if(ve[j]) {
				if(f) {
					ans=ans&v[j];
					f=0;
				}
				ans=max(ans,k&v[j]);
			}
		}
		for(int j=0; j<n; j++) {
			if(k&v[j]==ans) {
				ve[j]=0;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

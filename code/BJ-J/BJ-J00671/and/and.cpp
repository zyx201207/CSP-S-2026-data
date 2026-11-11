#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=2147483647;
vector<int>a;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}

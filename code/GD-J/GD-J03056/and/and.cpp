#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int a[N];
int n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;++i){
			ans = max(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
}

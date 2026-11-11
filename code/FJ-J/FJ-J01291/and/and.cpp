#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	int a[maxn];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans = max(ans,a[i]);
	}
	cout<<ans;
}

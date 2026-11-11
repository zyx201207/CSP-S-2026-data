#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxx++;
		}
	}
	cout<<a[n];
	
	return 0;
}

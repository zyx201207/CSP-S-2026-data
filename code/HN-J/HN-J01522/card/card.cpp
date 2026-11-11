#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,m,l,z[N];
long long ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) z[a[i]]=i;
	for(int i=1;i<=n;i++){
		l=i;
		while(l<=n){
			ans[a[l]]++;
			l=z[a[l]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';	
	return 0;
}

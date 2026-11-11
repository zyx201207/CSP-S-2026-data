#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],ans,k=1;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i-1]==a[i]){
			ans++;
		}else{
			cout<<ans+k<<' ';
			k++;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long a[N],n,m,ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			ans[a[l]]++;
			int r=n;
			while(a[l]!=a[r])r--;
			l=r+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

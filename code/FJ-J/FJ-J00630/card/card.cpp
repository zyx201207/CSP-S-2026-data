#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],k[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=n;i>=1;i--){
			cout << a[i] << ' ';
		}
	}
	return 0;
}

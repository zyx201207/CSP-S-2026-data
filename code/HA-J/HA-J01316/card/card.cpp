#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N=5e5+5,M=3e5+5;
int a[N],b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]&&a[i]!=a[i]+1){
			b[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout << b[i] << " " ;
	}
	return 0;
}
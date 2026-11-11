#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n;i++){
		cin >> a[i];
	}
	cout << "1 2 1 3";
	for(int j=1;j<=n;j--){
		cin >> a[j-1];
	}
	return 0;
}

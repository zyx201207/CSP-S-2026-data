#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cout << a[i] << ' ';
	}
	return 0;
}

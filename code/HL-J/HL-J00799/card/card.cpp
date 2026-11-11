#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=m;i++)cout << a[i] << " ";
}
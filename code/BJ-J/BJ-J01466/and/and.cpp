#include<bits/stdc++.h>
using namespace std;
int main{
	freopen(“and.in”,“r”,stdin);
	freopen(“and.out”,“w”,stdout);
	int n,m,ansmax=0;
	cin >> n >> m;
	int a[n+5];
	for(int i = 1,i <= n,i++){
		cin >> a[i];
	for(int j = 1,j <= m,j++){
		for(int p = 1,p <= n,p++){
			ansmax = &&a[p],a[m];
		}
	}
	cout << ansmax;
	return 0;
}
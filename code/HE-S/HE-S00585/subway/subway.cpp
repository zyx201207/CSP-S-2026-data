#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,sum;
int a[100001];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 cin>>c>>n>>m>>d>>q;
	 for(int i = 0;i <= m;i++){
	 	cin >> a[i];
	 }
	 for(int i = 1;i<=m;i++){
        sum = a[i]+= a[i];
        sum /= sum;
	 }
	 cout << sum;
	return 0;
}

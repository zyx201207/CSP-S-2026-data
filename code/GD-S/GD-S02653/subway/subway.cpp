#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c,n,m,d,q,w[N],a[N][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 cin >> c >> n >> m >> d >> q;
	 for(int i = 1;i <= m;i++){
	 	cin >> w[i];
	 }
	 for(int i = 1;i <= n;i++){
		int k;
		cin >> a[i][k]; 
	 }
	 while(q--){
	 	int x,y;
	 	long long sum;
	 	cin >> x >> y;
	 	sum = sum + w[x] + w[y];
	 	int t = a[1][1];
	 	for(int i = 1;i <= n;i++){
	 		sum += t;
		 }
		 cout << t << "\n";
	 }
	 return 0;
}
